<div align="center">

# Music Player

### Offline desktop MP3 player built with Qt

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-6-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![Qt Multimedia](https://img.shields.io/badge/Qt%20Multimedia-audio%20playback-41CD52?style=for-the-badge)]()
[![Windows](https://img.shields.io/badge/platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)]()

<br/>

[![Offline](https://img.shields.io/badge/offline-no%20server-22c55e?style=flat-square)]()
[![MP3](https://img.shields.io/badge/format-MP3-8b5cf6?style=flat-square)]()
[![Playlist](https://img.shields.io/badge/playlist-folder%20scan-3b82f6?style=flat-square)]()
[![Cover art](https://img.shields.io/badge/metadata-ID3%20artwork-f59e0b?style=flat-square)]()

<br/>

[![GitHub last commit](https://img.shields.io/github/last-commit/hackerbotfz/C-music-player?style=flat-square&logo=github)](https://github.com/hackerbotfz/C-music-player/commits)
[![GitHub repo size](https://img.shields.io/github/repo-size/hackerbotfz/C-music-player?style=flat-square&logo=github)](https://github.com/hackerbotfz/C-music-player)
[![GitHub stars](https://img.shields.io/github/stars/hackerbotfz/C-music-player?style=flat-square&logo=github)](https://github.com/hackerbotfz/C-music-player/stargazers)

<br/>

**[Faiz Lawan](https://github.com/hackerbotfz)**

</div>

---

A native **Qt 6** desktop music player for local **MP3** libraries. Pick a folder, browse tracks in a playlist, and control playback with play/pause, seek, volume, mute, and automatic advance to the next track. Album art is read from file metadata with a bundled fallback cover.

## Overview

| Feature | Detail |
|---------|--------|
| **Library** | Load any directory of `.mp3` files via file menu |
| **Playback** | `QMediaPlayer` + `QAudioOutput` with position and duration sliders |
| **Controls** | Play/pause, seek to start, double-click seek for previous track, next track |
| **Volume** | Slider (0–100) and mute toggle with standard media icons |
| **Queue** | Auto-advance on track end; circular playlist navigation |
| **Artwork** | Embedded cover from ID3 tags, else default image from Qt resources |

## Architecture

```mermaid
flowchart LR
    UI[mainwindow.ui] --> MW[MainWindow]
    MW --> MP[QMediaPlayer]
    MW --> AO[QAudioOutput]
    MW --> LW[QListWidget playlist]
    MP --> FILES[Local MP3 files]
    MP --> META[ID3 metadata / cover art]
```

Single-window app: **MainWindow** owns the media pipeline, playlist state (`QStringList` + `QDir`), and UI bindings defined in Qt Designer.

## Tech stack

C++17 · Qt Widgets · Qt Multimedia · qmake

## Run

Open `MusicPlayer.pro` in **Qt Creator**, configure the **Desktop** kit (MSVC or MinGW on Windows), then **Build → Run**.

Requires the **Qt Multimedia** module (`QT += multimedia`).

## Repository

```
Music_Player/
├── MusicPlayer.pro
├── resources.qrc
├── src/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   └── mainwindow.ui
├── assets/
│   └── default-cover.jpg
└── README.md
```

## License

© Faiz Lawan.
