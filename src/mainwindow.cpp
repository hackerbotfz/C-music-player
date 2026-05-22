#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor for MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize media player and audio output
    MPlayer = new QMediaPlayer();
    AudioSS = new QAudioOutput();
    songList = QStringList();
    MPlayer ->setAudioOutput(AudioSS);
    MetaData = new QMediaMetaData;

    // Set icons for play, seek back, and seek forward buttons
    ui ->Push_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui ->Push_seekback->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui ->Push_seekfoward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    // Set range and initial value for volume slider
    ui->horizontalSlider_2->setMinimum(0);
    ui->horizontalSlider_2->setMaximum(100);
    ui->horizontalSlider_2->setValue(30);

    // Set initial volume for audio output
    AudioSS->setVolume(ui->horizontalSlider_2->value());

    // Connect signals and slots for media player and UI elements
    connect(MPlayer,&QMediaPlayer::durationChanged,this, &MainWindow::durationChanged);
    connect(MPlayer,&QMediaPlayer::positionChanged,this, &MainWindow::positionChanged);
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &MainWindow::loadSong);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::setPlayerPosition);
    connect(MPlayer, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::on_MPlayer_mediaStatusChanged);

    // Initialize timer for seek back button
    seekBackTimer = new QTimer(this);
    seekBackTimer->setSingleShot(true);
    connect(seekBackTimer, &QTimer::timeout, this, &MainWindow::on_Push_seekback_clicked);

    // Set range for song progress slider
    ui->horizontalSlider->setRange(0,MPlayer->duration() / 1000);
}

// Destructor for MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

// Update duration labels based on current duration
void MainWindow::updateduration(qint64 duration)
{
    QString timestr;
    if (duration > 0)
    {
        QTime currentTime(0, 0, 0);
        currentTime = currentTime.addMSecs(duration);
        QTime totalTime(0, 0, 0);
        totalTime = totalTime.addMSecs(Mduration * 1000);
        QString format = "mm:ss";
        if (Mduration > 3600)
        {
            format = "hh:mm:ss";
        }
        ui->label_3->setText(currentTime.toString(format));
        ui->label_4->setText(totalTime.toString(format));
    }
}

// Update maximum value of progress slider and duration labels when song duration changes
void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration / 1000;
    ui->horizontalSlider->setMaximum(Mduration);
    updateduration(duration);
}

// Load next song when current song ends
void MainWindow::on_MPlayer_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        currentSongIndex = (currentSongIndex + 1) % songList.size();
        loadSong(currentSongIndex);
    }
}

// Update progress slider and duration labels when song progress changes
void MainWindow::positionChanged(qint64 progress)
{
    if (!ui->horizontalSlider->isSliderDown())
    {
        ui->horizontalSlider->setValue(progress / 1000);
    }
    updateduration(progress);
}

// Mute or unmute audio output when mute button is clicked
void MainWindow::on_pushButton_clicked()
{
    if (IS_MUTED == false)
    {
        ui -> pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        IS_MUTED = true;
        AudioSS->setMuted(true);
    }
    else
    {
        ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        IS_MUTED = false;
        AudioSS->setMuted(false);
    }

}

// Select directory for song files when select file action is triggered
void MainWindow::on_actionSelect_File_triggered()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Select Directory"));
    dir = QDir(dirName);
    QStringList filters;
    filters << "*.mp3";
    songList.clear();
    ui->listWidget->clear();
    songList = dir.entryList(filters);
    ui->listWidget->addItems(songList);
}

// Play or pause song when play button is clicked
void MainWindow::on_Push_play_clicked()
{
    if (is_Playing) {
        MPlayer->pause();
        ui ->Push_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    } else {
        MPlayer->play();
        ui ->Push_play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    is_Playing = !is_Playing;
}

// Seek back to beginning of song or go to previous song when seek back button is clicked
void MainWindow::on_Push_seekback_clicked()
{
    if (seekBackTimer->isActive()) {
        // If the timer is still active, this is a double click
        seekBackTimer->stop();
        on_Push_seekback_doubleClicked();
    } else {
        // If the timer is not active, this is a single click
        seekBackTimer->start(0); // 250 ms until the timer times out
        MPlayer->setPosition(0); // Add this line to go back to the beginning of the song
    }
}

// Go to previous song when seek back button is double clicked
void MainWindow::on_Push_seekback_doubleClicked()
{
    currentSongIndex = (currentSongIndex - 1 + songList.size()) % songList.size(); // Go to the previous song
    loadSong(currentSongIndex);
}

// Go to next song when seek forward button is clicked
void MainWindow::on_Push_seekfoward_clicked()
{
    currentSongIndex = (currentSongIndex + 1) % songList.size();
    loadSong(currentSongIndex);
    ui ->Push_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    is_Playing = false;
}

// Set song progress when progress slider is moved
void MainWindow::setPlayerPosition(int position)
{
    MPlayer->setPosition(position * 1000);
}

// Set volume when volume slider value changes
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    qreal volume = value / 100.0;
    AudioSS->setVolume(volume);
}

// Load song when song in list is selected
void MainWindow::loadSong(int index)
{
    if (index >= 0 && index < songList.size()) {
        QString fileName = songList.at(index);
        QUrl mediaUrl = QUrl::fromLocalFile(QDir::cleanPath(dir.absolutePath() + QDir::separator() + fileName));
        MPlayer->setSource(mediaUrl);

        QFileInfo fileInfo(fileName);
        ui->label->setText(fileInfo.fileName());

        // Connect to the metaDataChanged signal of QMediaPlayer
        connect(MPlayer, &QMediaPlayer::metaDataChanged, this, &MainWindow::updateMetaData);

        // Start playing the song
        MPlayer->play();

        // Set the pause icon
        ui ->Push_play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        is_Playing = true;
    }
}

// Update cover art image when song metadata changes
void MainWindow::updateMetaData()
{
    QMediaMetaData metaData = MPlayer->metaData();
    QVariant coverArtVariant = metaData.value(QMediaMetaData::CoverArtImage);

    if (coverArtVariant.canConvert<QImage>()) {
        QImage coverImage = qvariant_cast<QImage>(coverArtVariant);
        if (!coverImage.isNull()) {
            ui->label_2->setPixmap(QPixmap::fromImage(coverImage));
            ui->label_2->setScaledContents(true);
            return;
        }
    }

    QPixmap defaultPixmap(":/assets/default-cover.jpg");
    if (!defaultPixmap.isNull()) {
        ui->label_2->setPixmap(defaultPixmap);
        ui->label_2->setScaledContents(true);
    }
}
