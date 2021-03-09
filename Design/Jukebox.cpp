/*
1. Entities: Jukebox, Song, Artist, Album, Playlist
2. Jukebox will have a list of songs organized by albums and artists and genre
3. User is able to search a song by name, album name, artist name or genre
4. User is able to get details of a song and play it
5. Create playlists and add/remove songs in it.
 */

class Jukebox {
	list<Song> songs; // use unordered_map<int, Song> for O(1) operations (song id, song)
	list<Playlist> playlists;

public:
	Jukebox(list<Song> songs) {
		for (Song s : songs) this->songs.push_back(s);
	}
	void playSong(Song song);
	void playPlaylist(Playlist playlist);
	void addSong(Song song);
	void removeSong(Song song);
	bool createPlaylist(string name) {
		playlists.push_back(new Playlist(name));
	}
	void removePlaylist(Playlist playlist) {
		list.erase(find(list.begin(), list.end(), playlist->getId()));
	}
	void addSongToPlaylist(Playlist playlist, Song song) {
		playlist.addSong(song);
	}
	void removeSongFromPlaylist(Playlist playlist, Song song) {
		playlist.removeSong(song);
	}
	list<Song> getAllSongs();
	list<Song> searchSongByName(string name);
	Song getSongById(int songId);
	list<Playlist> getAllPlaylists();
	list<Playlist> searchPlaylistByName(string name);
	Playlist getPlaylistById(int playlistId);
};

class Song {
	int id;
	string title;
	Artist artist;
	Album album;
	int duration_in_seconds;
	Lyrics lyrics;
	SongFormat songFormat;
public:
	void play();
	void pause();
	void stop();
	// ... getters and setters
	string getSongName();
	void setSongName();
	string getArtist();
	void setArtist();
	string getAlbum();
	void setAlbum();
};

enum songFormat {
	MP3, AAC, WMV
};

class Lyrics {
	string lyric;
	string timestamp;
};

class Playlist {
	int id;
	string name;
	list<Song> songs;
	time_t created_at; // in unix timestamp
public:
	Playlist(string name) {
		this->name = name;
		songs = new vector<Song>();
		created_at = time(NULL);
	}
	int getId() { return id; }
	void play();
	bool addSong(Song song);
	bool removeSong(Song song);

	// getters and setters
	list<Song> getPlaylistSongs();
	string getPlaylistName();
};

class Artist {
	int artistId;
	string name;
}