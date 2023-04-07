#ifndef APP_HPP
#define APP_HPP

#include <QtWidgets>

#include "winctl.hpp"
#include "window.hpp"

#define DEFAULT_CLIENT_APP_PATH "spotify"
#define DEFAULT_CLIENT_LD_PRELOAD "LD_PRELOAD=/usr/local/lib/spotify-adblock.so"
#define DEFAULT_FLATPAK_LD_PRELOAD "--env=\"LD_PRELOAD=$HOME/.spotify-adblock/spotify-adblock.so:\""
#define CLIENT_FIND_ATTEMPTS 5

class SpotifyTrayApp : public QApplication {
    Q_OBJECT

    // Spotify process handle
    QProcess spotifyProcess;

    QProcessEnvironment spotifyEnv;

    // Spotify window data
    WindowData spotify;

    // Arguments to pass to Spotify
    QStringList spotifyArgs;

  public:
    // Main window pointer
    SpotifyFrame* mainFrame;

  private slots:
    void commitData(QSessionManager& manager);

  public:
    SpotifyTrayApp(int &argc, char **argv);

    virtual ~SpotifyTrayApp();

    WindowData startSpotify(const QStringList& args);

    void stopSpotify();

};

#endif
