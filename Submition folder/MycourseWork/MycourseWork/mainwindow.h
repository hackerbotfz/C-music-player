#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QtMultimedia>
#include <QtCore>
#include <QtWidgets>
#include <QAudioOutput>
#include <QMediaMetaData>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void durationChanged(qint64 duration);

    void positionChanged(qint64 progress);

    void loadSong(int index);

    void on_pushButton_clicked();

    void on_actionSelect_File_triggered();

    void on_Push_seekback_clicked();

    void on_Push_seekback_doubleClicked();

    void on_Push_play_clicked();

    void on_Push_seekfoward_clicked();

    void on_MPlayer_mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void on_horizontalSlider_2_valueChanged(int value);

    void updateMetaData();

    void setPlayerPosition(int position);

private:
    QTimer *seekBackTimer;
    QStringList songList;
    QDir dir;
    int currentSongIndex = 0;
    void updateduration(qint64 duration);
    Ui::MainWindow *ui;
    bool is_Playing = false;
    bool IS_MUTED = false;
    QMediaPlayer *MPlayer;
    QListWidget *songListWidget;
    QMediaMetaData *MetaData;
    QAudioOutput *AudioSS;
    qint64 Mduration;
};
#endif // MAINWINDOW_H
