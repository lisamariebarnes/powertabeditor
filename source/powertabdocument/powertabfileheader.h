/////////////////////////////////////////////////////////////////////////////
// Name:            powertabfileheader.h
// Purpose:         Stores all of the information found in the header of a Power Tab file
// Author:          Brad Larsen
// Modified by:     
// Created:         Dec 4, 2004
// RCS-ID:          
// Copyright:       (c) Brad Larsen
// License:         wxWindows license
/////////////////////////////////////////////////////////////////////////////

#ifndef __POWERTABFILEHEADER_H__
#define __POWERTABFILEHEADER_H__

#include <stdint.h>
#include <string>
using std::string;

#include "powertabinputstream.h"
#include "powertaboutputstream.h"
#include "macros.h"

/// Stores all of the information found in the header of a Power Tab file
class PowerTabFileHeader
{
// Constants
public:
    static const uint32_t POWERTABFILE_MARKER;                      ///< Special marker that appears at the start of every Power Tab file

    static const uint16_t NUM_FILEVERSIONS;                           ///< Number of power tab file formats
    static const uint16_t FILEVERSION_1_0;                            ///< Version 1.0        Feb. 6, 2000
    static const uint16_t FILEVERSION_1_0_2;                          ///< Version 1.0.2      Feb. 21, 2000
    static const uint16_t FILEVERSION_1_5;                            ///< Version 1.5        May. 22, 2000
    static const uint16_t FILEVERSION_1_7;                            ///< Version 1.7        Aug. 30, 2000
    static const uint16_t FILEVERSION_CURRENT;                        ///< Current version of power tab file format
    
    static const uint8_t NUM_FILETYPES;                              ///< Number of file types
    static const uint8_t FILETYPE_SONG;                              ///< File is a song
    static const uint8_t FILETYPE_LESSON;                            ///< File is a lesson

    static const uint8_t CONTENTTYPE_NONE;                           ///< File contains no content
    static const uint8_t CONTENTTYPE_GUITAR;                         ///< File contains guitar score content
    static const uint8_t CONTENTTYPE_BASS;                           ///< File contains bass score content
    static const uint8_t CONTENTTYPE_PERCUSSION;                     ///< File contains percussion score content
    static const uint8_t CONTENTTYPE_ALL;                            ///< File contains guitar score & bass score & percussion score content

    static const uint8_t NUM_RELEASETYPES;                           ///< Number of release types
    static const uint8_t RELEASETYPE_PUBLIC_AUDIO;                   ///< Song was released to the public in an audio format (cd, tape, etc.)
    static const uint8_t RELEASETYPE_PUBLIC_VIDEO;                   ///< Song was released to the public in a video format (video tape, dvd, etc.)
    static const uint8_t RELEASETYPE_BOOTLEG;                        ///< Song is a bootleg
    static const uint8_t RELEASETYPE_NOTRELEASED;                    ///< Song was never released (self-composition)
    
    static const uint8_t NUM_AUDIORELEASETYPES;                      ///< Number of audio release types
    static const uint8_t AUDIORELEASETYPE_SINGLE;                    ///< Song was released on a single
    static const uint8_t AUDIORELEASETYPE_EP;                        ///< Song was released on an EP 
    static const uint8_t AUDIORELEASETYPE_ALBUM;                     ///< Song was released on a "normal" album
    static const uint8_t AUDIORELEASETYPE_DOUBLEALBUM;               ///< Song was released on a double album
    static const uint8_t AUDIORELEASETYPE_TRIPLEALBUM;               ///< Song was released on a triple album
    static const uint8_t AUDIORELEASETYPE_BOXSET;                    ///< Song was released on a boxset compilation
    
    static const uint8_t NUM_AUTHORTYPES;                            ///< Number of author types
    static const uint8_t AUTHORTYPE_AUTHORKNOWN;                     ///< The author of the song is known
    static const uint8_t AUTHORTYPE_TRADITIONAL;                     ///< The author of the song is unknown (i.e. Greensleeves)
    
    static const uint16_t NUM_MUSICSTYLES;                            ///< Number of music styles (used by lessons)
    static const uint16_t MUSICSTYLE_ALTERNATIVE;
    static const uint16_t MUSICSTYLE_BLUEGRASS;
    static const uint16_t MUSICSTYLE_BLUES;
    static const uint16_t MUSICSTYLE_COUNTRY;
    static const uint16_t MUSICSTYLE_FINGERPICK;
    static const uint16_t MUSICSTYLE_FLAMENCO;
    static const uint16_t MUSICSTYLE_FOLK;
    static const uint16_t MUSICSTYLE_FUNK;
    static const uint16_t MUSICSTYLE_FUSION;
    static const uint16_t MUSICSTYLE_GENERAL;
    static const uint16_t MUSICSTYLE_JAZZ;
    static const uint16_t MUSICSTYLE_METAL;
    static const uint16_t MUSICSTYLE_OTHER;
    static const uint16_t MUSICSTYLE_POP;
    static const uint16_t MUSICSTYLE_PROGRESSIVE;
    static const uint16_t MUSICSTYLE_PUNK;
    static const uint16_t MUSICSTYLE_REGGAE;
    static const uint16_t MUSICSTYLE_ROCK;
    static const uint16_t MUSICSTYLE_SWING;
    
    static const uint8_t NUM_LESSONLEVELS;                           ///< Number of lesson difficulty levels
    static const uint8_t LESSONLEVEL_BEGINNER;                       ///< Easy
    static const uint8_t LESSONLEVEL_INTERMEDIATE;                   ///< Average
    static const uint8_t LESSONLEVEL_ADVANCED;                       ///< Difficult

    // Compatibility Constants (used by v1.0-v1.5 formats)
protected:
    static const uint8_t NUM_RELEASEDONS;
    static const uint8_t RO_SINGLE;
    static const uint8_t RO_EP;
    static const uint8_t RO_LP;
    static const uint8_t RO_DOUBLELP;
    static const uint8_t RO_TRIPLELP;
    static const uint8_t RO_BOXSET;
    static const uint8_t RO_BOOTLEG;
    static const uint8_t RO_DEMO;
    static const uint8_t RO_SOUNDTRACK;
    static const uint8_t RO_VIDEO;
    static const uint8_t RO_NONE;
    
// Member Variables
protected:
    uint16_t      m_version;                                          ///< Version number of the file format
    uint8_t      m_fileType;                                         ///< Type of file
    
    // Song type data
    struct SONG_DATA
    {
        uint8_t      contentType;                                    ///< Type of content in the file (guitar score, bass score, percussion score)
        string    title;                                          ///< Title of the song
        string    artist;                                         ///< Artist who performed song
        uint8_t      releaseType;                                    ///< How the song was released (if released)

        struct AUDIO_DATA
        {
            uint8_t      type;                                       ///< Type of audio release the song was released on (single, EP, LP, double LP, etc)
            string    title;                                      ///< Title of the audio release
            uint16_t      year;                                       ///< Year the audio release was released
            uint8_t      live;                                       ///< Determines whether the song is a live performance
        } audioData;

        struct  VIDEO_DATA
        {
            string    title;                                      ///< Title of video the song was released on
            uint8_t      live;                                       ///< Determines whether the song is a live performance
        } videoData;

        struct BOOTLEG_DATA
        {
            string title;                                         ///< Title of the bootleg
            uint16_t  month;                                          ///< Date of bootleg (month is one based)
            uint16_t  day;
            uint16_t  year;
        } bootlegData;

        uint8_t authorType;                                          ///< Author type (known or unknown/traditional)

        struct AUTHOR_DATA
        {
            string composer;                                      ///< Author of the song's music
            string lyricist;                                      ///< Author of the song's lyrics
        } authorData;
        
        string arranger;                                          ///< Performer who arranged the version of the song
        
        string guitarScoreTranscriber;                            ///< Transcriber of the guitar score
        string bassScoreTranscriber;                              ///< Transcriber of the bass score
        
        string copyright;                                         ///< Copyright notice
        
        string lyrics;                                            ///< Song lyrics
        
        string guitarScoreNotes;                                  ///< Notes for the guitar score
        string bassScoreNotes;                                    ///< Notes for the base score
    } m_songData;

    // Lesson type data
    struct LESSON_DATA
    {
        string    title;                                          ///< Title of the lesson
        string    subtitle;                                       ///< Subtitle for the lesson
        uint16_t      musicStyle;                                     ///< Style of the music the lesson encompasses
        uint8_t      level;                                          ///< Level of difficulty for the lesson
        string    author;                                         ///< Author of the lesson
        string    notes;                                          ///< Notes for the lesson
        string    copyright;                                      ///< Copyright for lesson
    } m_lessonData;

// Constructor/Destructor
public:
    PowerTabFileHeader();
    PowerTabFileHeader(const PowerTabFileHeader& header);
    ~PowerTabFileHeader();

// Operators
    const PowerTabFileHeader& operator=(const PowerTabFileHeader& header);
    bool operator==(const PowerTabFileHeader& header) const;
    bool operator!=(const PowerTabFileHeader& header) const;

// Serialization Functions
    bool Serialize(PowerTabOutputStream& stream);
    bool Deserialize(PowerTabInputStream& stream);
    bool DeserializeVersion1_7(PowerTabInputStream& stream);
    bool DeserializeVersion1_5(PowerTabInputStream& stream);
    bool DeserializeVersion1_0(PowerTabInputStream& stream);
    
// Header Functions
    /// Determines if a marker is a valid Power Tab file marker
    static bool IsValidPowerTabFileMarker(uint32_t marker)          
        {return (marker == POWERTABFILE_MARKER);}
    
// Version Functions
    /// Determines if a file version is valid
    /// @param version File version to validate
    /// @return True if the file version is valid, false if not
    static bool IsValidFileVersion(uint16_t version)                  
    {
        return ((version >= FILEVERSION_1_0) &&
            (version <= FILEVERSION_CURRENT));
    }
    /// Sets the file version (see FILEVERSION_ constants for values)
    /// @param version File version to set
    /// @return True if the file version was set, false if not
    bool SetVersion(uint16_t version)                                 
    {
        CHECK_THAT(IsValidFileVersion(version), false);
        m_version = version;
        return (true);
    }
    /// Gets the file version
    /// @return The file version
    uint16_t GetVersion() const                                       
        {return (m_version);}

// File Type Functions
    /// Determines if a file type is valid
    /// @param fileType File type to validate
    /// @return True if the file type is valid, false if not
    static bool IsValidFileType(uint8_t fileType)                    
        {return (fileType < NUM_FILETYPES);}
    /// Sets the file type (see FILETYPE_ constants for values)
    /// @param fileType File type to set
    /// @return True if the file type was set, false if not
    bool SetFileType(uint8_t fileType)                               
    {
        CHECK_THAT(IsValidFileType(fileType), false);
        m_fileType = fileType;
        return (true);
    }
    /// Gets the file type
    /// @return The file type
    uint8_t GetFileType() const                                      
        {return (m_fileType);}
    /// Sets the file type to be a song
    void SetSong()                                                  
        {SetFileType(FILETYPE_SONG);}
    /// Determines if the file type is a song
    /// @return True if the file type is a song, false if not
    bool IsSong() const                                             
        {return (GetFileType() == FILETYPE_SONG);}
    /// Sets the file type to be a lesson
    void SetLesson()                                                
        {SetFileType(FILETYPE_LESSON);}
    /// Determines if the file type is a lesson
    /// @return True if the file type is a lesson, false if not
    bool IsLesson() const                                           
        {return (GetFileType() == FILETYPE_LESSON);}

// Song Functions
    /// Determines if a content type is valid
    /// @param contentType Content type to validate
    /// @return True if the content type is valid, false if not
    static bool IsValidSongContentType(uint8_t contentType)          
        {return (contentType <= CONTENTTYPE_ALL);}
    /// Sets the song content type (see CONTENTTYPE_ constants for values)
    /// @param contentType Content type to set
    /// @return True if the content type was set, false if not
    bool SetSongContentType(uint8_t contentType)                     
    {
        CHECK_THAT(IsValidSongContentType(contentType), false);
        m_songData.contentType = contentType;
        return (true);
    }
    /// Gets the song content type
    /// @return The song content type
    uint8_t GetSongContentType() const                               
        {return (m_songData.contentType);}

    /// Sets the song title
    /// @param title Song title to set
    /// @return True if the song title was set, false if not
    bool SetSongTitle(const char* title)                          
    {
        CHECK_THAT(title != NULL, false);
        m_songData.title = title;
        return (true);
    }
    /// Gets the song title
    /// @return The song title
    string GetSongTitle() const                                   
        {return (m_songData.title);}

    /// Sets the song artist
    /// @param artist Song artist to set
    /// @return True if the song artist was set, false if not
    bool SetSongArtist(const char* artist)                        
    {
        CHECK_THAT(artist != NULL, false);
        m_songData.artist = artist;
        return (true);
    }
    /// Gets the song artist
    /// @return The song artist
    string GetSongArtist() const                                  
        {return (m_songData.artist);}

    /// Determines if a song release type is valid
    /// @param releaseType Release type to validate
    /// @return True if the release type is valid, false if not
    static bool IsValidSongReleaseType(uint8_t releaseType)          
        {return (releaseType < NUM_RELEASETYPES);}
    /// Sets the song release type (see RELEASETYPE_ constants for values)
    /// @param releaseType Release type to set
    /// @return True if the song release type was set, false if not
    bool SetSongReleaseType(uint8_t releaseType)                     
    {
        CHECK_THAT(IsValidSongReleaseType(releaseType), false);
        m_songData.releaseType = releaseType;
        return (true);
    }
    /// Gets the song release type
    /// @return The song release type
    uint8_t GetSongReleaseType() const                               
        {return (m_songData.releaseType);}
    string GetSongReleaseTitle() const;

    /// Determines if an audio release type is valid
    /// @param audioReleaseType Audio release type to validate
    /// @return True if the album type is valid, false if not
    static bool IsValidAudioReleaseType(uint8_t audioReleaseType)    
        {return (audioReleaseType < NUM_AUDIORELEASETYPES);}
    /// Sets the song audio release type (see AUDIORELEASETYPE_ constants for
    /// values)
    /// @param type Audio release type to set
    /// @return True if the song audio release type was set, false if not
    bool SetSongAudioReleaseType(uint8_t type)                       
    {
        CHECK_THAT(IsValidAudioReleaseType(type), false);
        m_songData.audioData.type = type;
        return (true);
    }
    /// Gets the song audio release type
    /// @return The song audio release type
    uint8_t GetSongAudioReleaseType() const                          
        {return (m_songData.audioData.type);}

    /// Sets the song audio release title
    /// @param title Title to set
    /// @return True if the song audio release title was set, false if not
    bool SetSongAudioReleaseTitle(const char* title)              
    {
        CHECK_THAT(title != NULL, false);
        m_songData.audioData.title = title;
        return (true);
    }
    /// Gets the song audio release title
    /// @return The song audio release title
    string GetSongAudioReleaseTitle() const                       
        {return (m_songData.audioData.title);}

    /// Sets the song audio release year
    /// @param year Year to set
    void SetSongAudioReleaseYear(uint16_t year)                       
        {m_songData.audioData.year = year;}
    /// Gets the song audio release year
    /// @return The audio release year
    uint16_t GetSongAudioReleaseYear() const                          
        {return (m_songData.audioData.year);}

    /// Sets the song audio release live status
    /// @param set True to set the live status, false to clear it
    void SetSongAudioReleaseLive(bool set = true)                   
        {m_songData.audioData.live = ((set) ? 1 : 0);}
    /// Determines if the song audio release is live
    /// @return True if the song audio release is live, false if not
    bool IsSongAudioReleaseLive() const                             
        {return ((m_songData.audioData.live == 1) ? true : false);}

    /// Sets the song video release title
    /// @param title Title to set
    /// @return True if the video release title was set, false if not
    bool SetSongVideoReleaseTitle(const char* title)              
    {
        CHECK_THAT(title != NULL, false);
        m_songData.videoData.title = title;
        return (true);
    }
    /// Gets the song video release title
    /// @return The song video release title
    string GetSongVideoReleaseTitle() const                       
        {return (m_songData.videoData.title);}

    /// Sets the song video release live status
    /// @param set True to set the live status, false to clear it
    void SetSongVideoReleaseLive(bool set = true)                   
        {m_songData.videoData.live = ((set) ? 1 : 0);}
    /// Determines if the song video release is live
    /// @return True if the song video release is live, false if not
    bool IsSongVideoReleaseLive() const                             
        {return ((m_songData.videoData.live == 1) ? true : false);}

    /// Sets the song bootleg title
    /// @param title Title to set
    /// @return True if the song bootleg title was set, false if not
    bool SetSongBootlegTitle(const char* title)                   
    {
        CHECK_THAT(title != NULL, false);
        m_songData.bootlegData.title = title;
        return (true);
    }
    /// Gets the song bootleg title
    /// @return The song bootleg title
    string GetSongBootlegTitle() const                            
        {return (m_songData.bootlegData.title);}

    bool SetSongBootlegDate(uint16_t month, uint16_t day, uint16_t year);
    //wxDateTime GetSongBootlegDate() const;  TODO - replace this

    /// Determines if an author type is valid
    /// @param authorType Author type to validate
    /// @return True if the author type is valid, false if not
    static bool IsValidAuthorType(uint8_t authorType)                
        {return (authorType < NUM_AUTHORTYPES);}
    /// Sets the song author type (see AUTHORTYPE_ constants for values)
    /// @param authorType Author type to set
    /// @return True if the song author type was set, false if not
    bool SetSongAuthorType(uint8_t authorType)                       
    {
        CHECK_THAT(IsValidAuthorType(authorType), false);
        m_songData.authorType = authorType;
        return (true);
    }
    /// Gets the song author type
    /// @return The song author type
    uint8_t GetSongAuthorType() const                                
        {return (m_songData.authorType);}

    /// Sets the song composer
    /// @param composer Composer to set
    /// @return True if the song composer was set, false if not
    bool SetSongComposer(const char* composer)                    
    {
        CHECK_THAT(composer != NULL, false);
        m_songData.authorData.composer = composer;
        return (true);
    }
    /// Gets the song composer
    /// @return The song composer
    string GetSongComposer() const                                
        {return (m_songData.authorData.composer);}
    
    /// Sets the song lyricist
    /// @param lyricist Lyricist to set
    /// @return True if the song lyricist was set, false if not
    bool SetSongLyricist(const char* lyricist)                    
    {
        CHECK_THAT(lyricist != NULL, false);
        m_songData.authorData.lyricist = lyricist;
        return (true);
    }
    /// Gets the song lyricist
    /// @return The song lyricist
    string GetSongLyricist() const                                
        {return (m_songData.authorData.lyricist);}

    /// Sets the song arranger
    /// @param arranger Arranger to set
    /// @return True if the song arranger was set, false if not
    bool SetSongArranger(const char* arranger)                    
    {
        CHECK_THAT(arranger != NULL, false);
        m_songData.arranger = arranger;
        return (true);
    }
    /// Gets the song arranger
    /// @return The song arranger
    string GetSongArranger() const                                
        {return (m_songData.arranger);}
    
    /// Sets the song guitar score transcriber
    /// @param transcriber Transcriber to set
    /// @return True if the song guitar score transcriber was set, false if not
    bool SetSongGuitarScoreTranscriber(const char* transcriber)   
    {
        CHECK_THAT(transcriber != NULL, false);
        m_songData.guitarScoreTranscriber = transcriber;
        return (true);
    }
    /// Gets the song guitar score transcriber
    /// @return The song guitar score transcriber
    string GetSongGuitarScoreTranscriber() const                  
        {return (m_songData.guitarScoreTranscriber);}

    /// Sets the song bass score transcriber
    /// @param transcriber Transcriber to set
    /// @return True if the song bass score transcriber was set, false if not
    bool SetSongBassScoreTranscriber(const char* transcriber)     
    {
        CHECK_THAT(transcriber != NULL, false);
        m_songData.bassScoreTranscriber = transcriber;
        return (true);
    }
    /// Gets the song bass score transcriber
    /// @return The song bass score transcriber
    string GetSongBassScoreTranscriber() const                    
        {return (m_songData.bassScoreTranscriber);}

    /// Sets the song copyright
    /// @param copyright Copyright to set
    /// @return True if the song copyright was set, false if not
    bool SetSongCopyright(const char* copyright)                  
    {
        CHECK_THAT(copyright != NULL, false);
        m_songData.copyright = copyright;
        return (true);
    }
    /// Gets the song copyright
    /// @return The song copyright
    string GetSongCopyright() const                               
        {return (m_songData.copyright);}

    /// Sets the song lyrics
    /// @param lyrics Lyrics to set
    /// @return True if the lyrics were set, false if not
    bool SetSongLyrics(const char* lyrics)                        
    {
        CHECK_THAT(lyrics != NULL, false);
        m_songData.lyrics = lyrics;
        return (true);
    }
    /// Gets the song lyrics
    /// @return The song lyrics
    string GetSongLyrics() const                                  
        {return (m_songData.lyrics);}

    /// Sets the song guitar score notes
    /// @param notes Notes to set
    /// @return True if the song guitar score notes were set, false if not
    bool SetSongGuitarScoreNotes(const char* notes)               
    {
        CHECK_THAT(notes != NULL, false);
        m_songData.guitarScoreNotes = notes;
        return (true);
    }
    /// Gets the song guitar score notes
    /// @return The song guitar score notes
    string GetSongGuitarScoreNotes() const                        
        {return (m_songData.guitarScoreNotes);}

    /// Sets the song bass score notes
    /// @param notes Notes to set
    /// @return True if the song bass score notes were set, false if not
    bool SetSongBassScoreNotes(const char* notes)                 
    {
        CHECK_THAT(notes != NULL, false);
        m_songData.bassScoreNotes = notes;
        return (true);
    }
    /// Gets the song bass score notes
    /// @return The song bass score notes
    string GetSongBassScoreNotes() const                          
        {return (m_songData.bassScoreNotes);}
    
// Lesson Functions
    /// Sets the lesson title
    /// @param title Title to set
    /// @return True if the title was set, false if not
    bool SetLessonTitle(const char* title)                        
    {
        CHECK_THAT(title != NULL, false);
        m_lessonData.title = title;
        return (true);
    }
    /// Gets the lesson title
    /// @return The lesson title
    string GetLessonTitle() const                                 
        {return (m_lessonData.title);}

    /// Sets the lesson subtitle
    /// @param subtitle Subtitle to set
    /// @return True if the subtitle was set, false if not
    bool SetLessonSubtitle(const char* subtitle)                  
    {
        CHECK_THAT(subtitle != NULL, false);
        m_lessonData.subtitle = subtitle;
        return (true);
    }
    /// Gets the lesson subtitle
    /// @return The lesson subtitle
    string GetLessonSubtitle() const                              
        {return (m_lessonData.subtitle);}

    /// Determines if a music musicStyle is valid
    /// @param musicStyle Music musicStyle to validate
    /// @return True if the music musicStyle is valid, false if not
    static bool IsValidMusicStyle(uint16_t musicStyle)                
        {return (musicStyle < NUM_MUSICSTYLES);}
    /// Sets the lesson music musicStyle
    /// @param musicStyle Music musicStyle to set
    /// @return True if the music musicStyle was set, false if not
    bool SetLessonMusicStyle(uint16_t musicStyle)                     
    {
        CHECK_THAT(IsValidMusicStyle(musicStyle), false);
        m_lessonData.musicStyle = musicStyle;
        return (true);
    }
    /// Gets the lesson music musicStyle
    /// @return The lesson music musicStyle
    uint16_t GetLessonMusicStyle() const                              
        {return (m_lessonData.musicStyle);}

    /// Determines if a lesson level is valid
    /// @param level Lesson level to validate
    /// @return True if the lesson level is valid, false if not
    static bool IsValidLessonLevel(uint8_t level)                    
        {return (level < NUM_LESSONLEVELS);}
    /// Sets the lesson level
    /// @param level Lesson level to set
    /// @return True if the lesson level was set, false if not
    bool SetLessonLevel(uint8_t level)                               
    {
        CHECK_THAT(IsValidLessonLevel(level), false);
        m_lessonData.level = level;
        return (true);
    }
    /// Gets the lesson level
    /// @return The lesson level
    uint8_t GetLessonLevel() const                                   
        {return (m_lessonData.level);}

    /// Sets the lesson author
    /// @param author Lesson author to set
    /// @return True if the lesson author was set, false if not
    bool SetLessonAuthor(const char* author)                      
    {
        CHECK_THAT(author != NULL, false);
        m_lessonData.author = author;
        return (true);
    }
    /// Gets the lesson author
    /// @return The lesson author
    string GetLessonAuthor() const                                
        {return (m_lessonData.author);}
    
    /// Sets the lesson notes
    /// @param notes Lesson notes to set
    /// @return True if the lesson notes were set, false if not
    bool SetLessonNotes(const char* notes)                        
    {
        CHECK_THAT(notes != NULL, false);
        m_lessonData.notes = notes;
        return (true);
    }
    /// Gets the lesson notes
    /// @return The lesson notes
    string GetLessonNotes() const                                 
        {return (m_lessonData.notes);}
    
    /// Sets the lesson copyright
    /// @param copyright Lesson copyright to set
    /// @return True if the lesson copyright was set, false if not
    bool SetLessonCopyright(const char* copyright)                
    {
        CHECK_THAT(copyright != NULL, false);
        m_lessonData.copyright = copyright;
        return (true);
    }
    /// Gets the lesson copyright
    /// @return The lesson copyright
    string GetLessonCopyright() const                             
        {return (m_lessonData.copyright);}

// Operations
    void LoadDefaults();
};

#endif