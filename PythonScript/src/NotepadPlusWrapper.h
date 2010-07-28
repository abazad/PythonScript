#ifndef _NOTEPADPLUSWRAPPER_H
#define _NOTEPADPLUSWRAPPER_H

#include "stdafx.h"
#include "Notepad_plus_msgs.h"
#include "menuCmdID.h"
#include "PluginInterface.h"
#include "ScintillaWrapper.h"

enum FormatType
{
	WIN_FORMAT, 
	MAC_FORMAT, 
	UNIX_FORMAT
};

enum BufferEncoding
{
	uni8Bit			= 0, 
	uniUTF8			= 1, 
	uni16BE			= 2, 
	uni16LE			= 3, 
	uniCookie		= 4, 
	uni7Bit			= 5, 
	uni16BE_NoBOM	= 6, 
	uni16LE_NoBOM	= 7, 
	uniEnd
};

enum StatusBarSection
{
	STATUSBARSECTION_DOCTYPE = STATUSBAR_DOC_TYPE,
	STATUSBARSECTION_DOCSIZE = STATUSBAR_DOC_SIZE,
	STATUSBARSECTION_CURPOS = STATUSBAR_CUR_POS,
	STATUSBARSECTION_EOFFORMAT = STATUSBAR_EOF_FORMAT,
	STATUSBARSECTION_UNICODETYPE = STATUSBAR_UNICODE_TYPE,
	STATUSBARSECTION_TYPINGMODE = STATUSBAR_TYPING_MODE
};

// enum for the notifications
enum Notification
{
	NPPNOTIF_READY = NPPN_READY,
	NPPNOTIF_TBMODIFICATION = NPPN_TBMODIFICATION,
	NPPNOTIF_FILEBEFORECLOSE = NPPN_FILEBEFORECLOSE,
	NPPNOTIF_FILEOPENED = NPPN_FILEOPENED,
	NPPNOTIF_FILECLOSED = NPPN_FILECLOSED,
	NPPNOTIF_FILEBEFOREOPEN = NPPN_FILEBEFOREOPEN,
	NPPNOTIF_FILEBEFORESAVE = NPPN_FILEBEFORESAVE,
	NPPNOTIF_FILESAVED = NPPN_FILESAVED,
	NPPNOTIF_SHUTDOWN = NPPN_SHUTDOWN,
	NPPNOTIF_BUFFERACTIVATED = NPPN_BUFFERACTIVATED,
	NPPNOTIF_LANGCHANGED = NPPN_LANGCHANGED,
	NPPNOTIF_WORDSTYLESUPDATED = NPPN_WORDSTYLESUPDATED,
	NPPNOTIF_SHORTCUTREMAPPED = NPPN_SHORTCUTREMAPPED,
	NPPNOTIF_FILEBEFORELOAD = NPPN_FILEBEFORELOAD,
	NPPNOTIF_FILELOADFAILED = NPPN_FILELOADFAILED,
	NPPNOTIF_READONLYCHANGED = NPPN_READONLYCHANGED
};

enum MessageBoxFlags
{
	NPPMB_OK = MB_OK,
	NPPMB_OKCANCEL = MB_OKCANCEL,
	NPPMB_ABORTRETRYIGNORE = MB_ABORTRETRYIGNORE,
	NPPMB_YESNOCANCEL = MB_YESNOCANCEL,
	NPPMB_YESNO = MB_YESNO,
	NPPMB_RETRYCANCEL = MB_RETRYCANCEL,
	NPPMB_CANCELTRYCONTINUE = MB_CANCELTRYCONTINUE,
	NPPMB_ICONHAND = MB_ICONHAND,
	NPPMB_ICONQUESTION = MB_ICONQUESTION,
	NPPMB_ICONEXCLAMATION = MB_ICONEXCLAMATION,
	NPPMB_ICONASTERISK = MB_ICONASTERISK,
	NPPMB_ICONWARNING = MB_ICONWARNING,
	NPPMB_ICONERROR = MB_ICONERROR,
	NPPMB_ICONINFORMATION = MB_ICONINFORMATION,
	NPPMB_ICONSTOP = MB_ICONSTOP,
	NPPMB_DEFBUTTON1 = MB_DEFBUTTON1,
	NPPMB_DEFBUTTON2 = MB_DEFBUTTON2,
	NPPMB_DEFBUTTON3 = MB_DEFBUTTON3,
	NPPMB_DEFBUTTON4 = MB_DEFBUTTON4
};


enum MenuCommands
{
	NPPIDM_FILE_NEW = IDM_FILE_NEW,
	NPPIDM_FILE_OPEN = IDM_FILE_OPEN,
	NPPIDM_FILE_CLOSE = IDM_FILE_CLOSE,
	NPPIDM_FILE_CLOSEALL = IDM_FILE_CLOSEALL,
	NPPIDM_FILE_CLOSEALL_BUT_CURRENT = IDM_FILE_CLOSEALL_BUT_CURRENT,
	NPPIDM_FILE_SAVE = IDM_FILE_SAVE,
	NPPIDM_FILE_SAVEALL = IDM_FILE_SAVEALL,
	NPPIDM_FILE_SAVEAS = IDM_FILE_SAVEAS,
	NPPIDM_FILE_PRINT = IDM_FILE_PRINT,
	NPPIDM_FILE_PRINTNOW = IDM_FILE_PRINTNOW,
	NPPIDM_FILE_EXIT = IDM_FILE_EXIT,
	NPPIDM_FILE_LOADSESSION = IDM_FILE_LOADSESSION,
	NPPIDM_FILE_SAVESESSION = IDM_FILE_SAVESESSION,
	NPPIDM_FILE_RELOAD = IDM_FILE_RELOAD,
	NPPIDM_FILE_SAVECOPYAS = IDM_FILE_SAVECOPYAS,
	NPPIDM_FILE_DELETE = IDM_FILE_DELETE,
	NPPIDM_FILE_RENAME = IDM_FILE_RENAME,
	NPPIDM_EDIT_CUT = IDM_EDIT_CUT,
	NPPIDM_EDIT_COPY = IDM_EDIT_COPY,
	NPPIDM_EDIT_UNDO = IDM_EDIT_UNDO,
	NPPIDM_EDIT_REDO = IDM_EDIT_REDO,
	NPPIDM_EDIT_PASTE = IDM_EDIT_PASTE,
	NPPIDM_EDIT_DELETE = IDM_EDIT_DELETE,
	NPPIDM_EDIT_SELECTALL = IDM_EDIT_SELECTALL,
	NPPIDM_EDIT_INS_TAB = IDM_EDIT_INS_TAB,
	NPPIDM_EDIT_RMV_TAB = IDM_EDIT_RMV_TAB,
	NPPIDM_EDIT_DUP_LINE = IDM_EDIT_DUP_LINE,
	NPPIDM_EDIT_TRANSPOSE_LINE = IDM_EDIT_TRANSPOSE_LINE,
	NPPIDM_EDIT_SPLIT_LINES = IDM_EDIT_SPLIT_LINES,
	NPPIDM_EDIT_JOIN_LINES = IDM_EDIT_JOIN_LINES,
	NPPIDM_EDIT_LINE_UP = IDM_EDIT_LINE_UP,
	NPPIDM_EDIT_LINE_DOWN = IDM_EDIT_LINE_DOWN,
	NPPIDM_EDIT_UPPERCASE = IDM_EDIT_UPPERCASE,
	NPPIDM_EDIT_LOWERCASE = IDM_EDIT_LOWERCASE,
	NPPIDM_MACRO_STARTRECORDINGMACRO = IDM_MACRO_STARTRECORDINGMACRO,
	NPPIDM_MACRO_STOPRECORDINGMACRO = IDM_MACRO_STOPRECORDINGMACRO,
	NPPIDM_MACRO_PLAYBACKRECORDEDMACRO = IDM_MACRO_PLAYBACKRECORDEDMACRO,
	NPPIDM_EDIT_BLOCK_COMMENT = IDM_EDIT_BLOCK_COMMENT,
	NPPIDM_EDIT_STREAM_COMMENT = IDM_EDIT_STREAM_COMMENT,
	NPPIDM_EDIT_TRIMTRAILING = IDM_EDIT_TRIMTRAILING,
	NPPIDM_MACRO_SAVECURRENTMACRO = IDM_MACRO_SAVECURRENTMACRO,
	NPPIDM_EDIT_RTL = IDM_EDIT_RTL,
	NPPIDM_EDIT_LTR = IDM_EDIT_LTR,
	NPPIDM_EDIT_SETREADONLY = IDM_EDIT_SETREADONLY,
	NPPIDM_EDIT_FULLPATHTOCLIP = IDM_EDIT_FULLPATHTOCLIP,
	NPPIDM_EDIT_FILENAMETOCLIP = IDM_EDIT_FILENAMETOCLIP,
	NPPIDM_EDIT_CURRENTDIRTOCLIP = IDM_EDIT_CURRENTDIRTOCLIP,
	NPPIDM_MACRO_RUNMULTIMACRODLG = IDM_MACRO_RUNMULTIMACRODLG,
	NPPIDM_EDIT_CLEARREADONLY = IDM_EDIT_CLEARREADONLY,
	NPPIDM_EDIT_COLUMNMODE = IDM_EDIT_COLUMNMODE,
	NPPIDM_EDIT_BLOCK_COMMENT_SET = IDM_EDIT_BLOCK_COMMENT_SET,
	NPPIDM_EDIT_BLOCK_UNCOMMENT = IDM_EDIT_BLOCK_UNCOMMENT,
	NPPIDM_EDIT_AUTOCOMPLETE = IDM_EDIT_AUTOCOMPLETE,
	NPPIDM_EDIT_AUTOCOMPLETE_CURRENTFILE = IDM_EDIT_AUTOCOMPLETE_CURRENTFILE,
	NPPIDM_EDIT_FUNCCALLTIP = IDM_EDIT_FUNCCALLTIP,
	NPPIDM_OPEN_ALL_RECENT_FILE = IDM_OPEN_ALL_RECENT_FILE,
	NPPIDM_CLEAN_RECENT_FILE_LIST = IDM_CLEAN_RECENT_FILE_LIST,
	NPPIDM_SEARCH_FIND = IDM_SEARCH_FIND,
	NPPIDM_SEARCH_FINDNEXT = IDM_SEARCH_FINDNEXT,
	NPPIDM_SEARCH_REPLACE = IDM_SEARCH_REPLACE,
	NPPIDM_SEARCH_GOTOLINE = IDM_SEARCH_GOTOLINE,
	NPPIDM_SEARCH_TOGGLE_BOOKMARK = IDM_SEARCH_TOGGLE_BOOKMARK,
	NPPIDM_SEARCH_NEXT_BOOKMARK = IDM_SEARCH_NEXT_BOOKMARK,
	NPPIDM_SEARCH_PREV_BOOKMARK = IDM_SEARCH_PREV_BOOKMARK,
	NPPIDM_SEARCH_CLEAR_BOOKMARKS = IDM_SEARCH_CLEAR_BOOKMARKS,
	NPPIDM_SEARCH_GOTOMATCHINGBRACE = IDM_SEARCH_GOTOMATCHINGBRACE,
	NPPIDM_SEARCH_FINDPREV = IDM_SEARCH_FINDPREV,
	NPPIDM_SEARCH_FINDINCREMENT = IDM_SEARCH_FINDINCREMENT,
	NPPIDM_SEARCH_FINDINFILES = IDM_SEARCH_FINDINFILES,
	NPPIDM_SEARCH_VOLATILE_FINDNEXT = IDM_SEARCH_VOLATILE_FINDNEXT,
	NPPIDM_SEARCH_VOLATILE_FINDPREV = IDM_SEARCH_VOLATILE_FINDPREV,
	NPPIDM_SEARCH_CUTMARKEDLINES = IDM_SEARCH_CUTMARKEDLINES,
	NPPIDM_SEARCH_COPYMARKEDLINES = IDM_SEARCH_COPYMARKEDLINES,
	NPPIDM_SEARCH_PASTEMARKEDLINES = IDM_SEARCH_PASTEMARKEDLINES,
	NPPIDM_SEARCH_DELETEMARKEDLINES = IDM_SEARCH_DELETEMARKEDLINES,
	NPPIDM_SEARCH_MARKALLEXT1 = IDM_SEARCH_MARKALLEXT1,
	NPPIDM_SEARCH_UNMARKALLEXT1 = IDM_SEARCH_UNMARKALLEXT1,
	NPPIDM_SEARCH_MARKALLEXT2 = IDM_SEARCH_MARKALLEXT2,
	NPPIDM_SEARCH_UNMARKALLEXT2 = IDM_SEARCH_UNMARKALLEXT2,
	NPPIDM_SEARCH_MARKALLEXT3 = IDM_SEARCH_MARKALLEXT3,
	NPPIDM_SEARCH_UNMARKALLEXT3 = IDM_SEARCH_UNMARKALLEXT3,
	NPPIDM_SEARCH_MARKALLEXT4 = IDM_SEARCH_MARKALLEXT4,
	NPPIDM_SEARCH_UNMARKALLEXT4 = IDM_SEARCH_UNMARKALLEXT4,
	NPPIDM_SEARCH_MARKALLEXT5 = IDM_SEARCH_MARKALLEXT5,
	NPPIDM_SEARCH_UNMARKALLEXT5 = IDM_SEARCH_UNMARKALLEXT5,
	NPPIDM_SEARCH_CLEARALLMARKS = IDM_SEARCH_CLEARALLMARKS,
	NPPIDM_SEARCH_GOPREVMARKER1 = IDM_SEARCH_GOPREVMARKER1,
	NPPIDM_SEARCH_GOPREVMARKER2 = IDM_SEARCH_GOPREVMARKER2,
	NPPIDM_SEARCH_GOPREVMARKER3 = IDM_SEARCH_GOPREVMARKER3,
	NPPIDM_SEARCH_GOPREVMARKER4 = IDM_SEARCH_GOPREVMARKER4,
	NPPIDM_SEARCH_GOPREVMARKER5 = IDM_SEARCH_GOPREVMARKER5,
	NPPIDM_SEARCH_GOPREVMARKER_DEF = IDM_SEARCH_GOPREVMARKER_DEF,
	NPPIDM_SEARCH_GONEXTMARKER1 = IDM_SEARCH_GONEXTMARKER1,
	NPPIDM_SEARCH_GONEXTMARKER2 = IDM_SEARCH_GONEXTMARKER2,
	NPPIDM_SEARCH_GONEXTMARKER3 = IDM_SEARCH_GONEXTMARKER3,
	NPPIDM_SEARCH_GONEXTMARKER4 = IDM_SEARCH_GONEXTMARKER4,
	NPPIDM_SEARCH_GONEXTMARKER5 = IDM_SEARCH_GONEXTMARKER5,
	NPPIDM_SEARCH_GONEXTMARKER_DEF = IDM_SEARCH_GONEXTMARKER_DEF,
	NPPIDM_FOCUS_ON_FOUND_RESULTS = IDM_FOCUS_ON_FOUND_RESULTS,
	NPPIDM_SEARCH_GOTONEXTFOUND = IDM_SEARCH_GOTONEXTFOUND,
	NPPIDM_SEARCH_GOTOPREVFOUND = IDM_SEARCH_GOTOPREVFOUND,
	NPPIDM_SEARCH_SETANDFINDNEXT = IDM_SEARCH_SETANDFINDNEXT,
	NPPIDM_SEARCH_SETANDFINDPREV = IDM_SEARCH_SETANDFINDPREV,
	NPPIDM_VIEW_TOOLBAR_REDUCE = IDM_VIEW_TOOLBAR_REDUCE,
	NPPIDM_VIEW_TOOLBAR_ENLARGE = IDM_VIEW_TOOLBAR_ENLARGE,
	NPPIDM_VIEW_TOOLBAR_STANDARD = IDM_VIEW_TOOLBAR_STANDARD,
	NPPIDM_VIEW_REDUCETABBAR = IDM_VIEW_REDUCETABBAR,
	NPPIDM_VIEW_LOCKTABBAR = IDM_VIEW_LOCKTABBAR,
	NPPIDM_VIEW_DRAWTABBAR_TOPBAR = IDM_VIEW_DRAWTABBAR_TOPBAR,
	NPPIDM_VIEW_DRAWTABBAR_INACIVETAB = IDM_VIEW_DRAWTABBAR_INACIVETAB,
	NPPIDM_VIEW_POSTIT = IDM_VIEW_POSTIT,
	NPPIDM_VIEW_TOGGLE_FOLDALL = IDM_VIEW_TOGGLE_FOLDALL,
	NPPIDM_VIEW_USER_DLG = IDM_VIEW_USER_DLG,
	NPPIDM_VIEW_LINENUMBER = IDM_VIEW_LINENUMBER,
	NPPIDM_VIEW_SYMBOLMARGIN = IDM_VIEW_SYMBOLMARGIN,
	NPPIDM_VIEW_FOLDERMAGIN = IDM_VIEW_FOLDERMAGIN,
	NPPIDM_VIEW_FOLDERMAGIN_SIMPLE = IDM_VIEW_FOLDERMAGIN_SIMPLE,
	NPPIDM_VIEW_FOLDERMAGIN_ARROW = IDM_VIEW_FOLDERMAGIN_ARROW,
	NPPIDM_VIEW_FOLDERMAGIN_CIRCLE = IDM_VIEW_FOLDERMAGIN_CIRCLE,
	NPPIDM_VIEW_FOLDERMAGIN_BOX = IDM_VIEW_FOLDERMAGIN_BOX,
	NPPIDM_VIEW_ALL_CHARACTERS = IDM_VIEW_ALL_CHARACTERS,
	NPPIDM_VIEW_INDENT_GUIDE = IDM_VIEW_INDENT_GUIDE,
	NPPIDM_VIEW_CURLINE_HILITING = IDM_VIEW_CURLINE_HILITING,
	NPPIDM_VIEW_WRAP = IDM_VIEW_WRAP,
	NPPIDM_VIEW_ZOOMIN = IDM_VIEW_ZOOMIN,
	NPPIDM_VIEW_ZOOMOUT = IDM_VIEW_ZOOMOUT,
	NPPIDM_VIEW_TAB_SPACE = IDM_VIEW_TAB_SPACE,
	NPPIDM_VIEW_EOL = IDM_VIEW_EOL,
	NPPIDM_VIEW_EDGELINE = IDM_VIEW_EDGELINE,
	NPPIDM_VIEW_EDGEBACKGROUND = IDM_VIEW_EDGEBACKGROUND,
	NPPIDM_VIEW_TOGGLE_UNFOLDALL = IDM_VIEW_TOGGLE_UNFOLDALL,
	NPPIDM_VIEW_FOLD_CURRENT = IDM_VIEW_FOLD_CURRENT,
	NPPIDM_VIEW_UNFOLD_CURRENT = IDM_VIEW_UNFOLD_CURRENT,
	NPPIDM_VIEW_FULLSCREENTOGGLE = IDM_VIEW_FULLSCREENTOGGLE,
	NPPIDM_VIEW_ZOOMRESTORE = IDM_VIEW_ZOOMRESTORE,
	NPPIDM_VIEW_ALWAYSONTOP = IDM_VIEW_ALWAYSONTOP,
	NPPIDM_VIEW_SYNSCROLLV = IDM_VIEW_SYNSCROLLV,
	NPPIDM_VIEW_SYNSCROLLH = IDM_VIEW_SYNSCROLLH,
	NPPIDM_VIEW_EDGENONE = IDM_VIEW_EDGENONE,
	NPPIDM_VIEW_DRAWTABBAR_CLOSEBOTTUN = IDM_VIEW_DRAWTABBAR_CLOSEBOTTUN,
	NPPIDM_VIEW_DRAWTABBAR_DBCLK2CLOSE = IDM_VIEW_DRAWTABBAR_DBCLK2CLOSE,
	NPPIDM_VIEW_REFRESHTABAR = IDM_VIEW_REFRESHTABAR,
	NPPIDM_VIEW_WRAP_SYMBOL = IDM_VIEW_WRAP_SYMBOL,
	NPPIDM_VIEW_HIDELINES = IDM_VIEW_HIDELINES,
	NPPIDM_VIEW_DRAWTABBAR_VERTICAL = IDM_VIEW_DRAWTABBAR_VERTICAL,
	NPPIDM_VIEW_DRAWTABBAR_MULTILINE = IDM_VIEW_DRAWTABBAR_MULTILINE,
	NPPIDM_VIEW_DOCCHANGEMARGIN = IDM_VIEW_DOCCHANGEMARGIN,
	NPPIDM_VIEW_FOLD = IDM_VIEW_FOLD,
	NPPIDM_VIEW_FOLD_1 = IDM_VIEW_FOLD_1,
	NPPIDM_VIEW_FOLD_2 = IDM_VIEW_FOLD_2,
	NPPIDM_VIEW_FOLD_3 = IDM_VIEW_FOLD_3,
	NPPIDM_VIEW_FOLD_4 = IDM_VIEW_FOLD_4,
	NPPIDM_VIEW_FOLD_5 = IDM_VIEW_FOLD_5,
	NPPIDM_VIEW_FOLD_6 = IDM_VIEW_FOLD_6,
	NPPIDM_VIEW_FOLD_7 = IDM_VIEW_FOLD_7,
	NPPIDM_VIEW_FOLD_8 = IDM_VIEW_FOLD_8,
	NPPIDM_VIEW_UNFOLD = IDM_VIEW_UNFOLD,
	NPPIDM_VIEW_UNFOLD_1 = IDM_VIEW_UNFOLD_1,
	NPPIDM_VIEW_UNFOLD_2 = IDM_VIEW_UNFOLD_2,
	NPPIDM_VIEW_UNFOLD_3 = IDM_VIEW_UNFOLD_3,
	NPPIDM_VIEW_UNFOLD_4 = IDM_VIEW_UNFOLD_4,
	NPPIDM_VIEW_UNFOLD_5 = IDM_VIEW_UNFOLD_5,
	NPPIDM_VIEW_UNFOLD_6 = IDM_VIEW_UNFOLD_6,
	NPPIDM_VIEW_UNFOLD_7 = IDM_VIEW_UNFOLD_7,
	NPPIDM_VIEW_UNFOLD_8 = IDM_VIEW_UNFOLD_8,
	NPPIDM_VIEW_GOTO_ANOTHER_VIEW = IDM_VIEW_GOTO_ANOTHER_VIEW,
	NPPIDM_VIEW_CLONE_TO_ANOTHER_VIEW = IDM_VIEW_CLONE_TO_ANOTHER_VIEW,
	NPPIDM_VIEW_GOTO_NEW_INSTANCE = IDM_VIEW_GOTO_NEW_INSTANCE,
	NPPIDM_VIEW_LOAD_IN_NEW_INSTANCE = IDM_VIEW_LOAD_IN_NEW_INSTANCE,
	NPPIDM_VIEW_SWITCHTO_OTHER_VIEW = IDM_VIEW_SWITCHTO_OTHER_VIEW,
	NPPIDM_FORMAT_TODOS = IDM_FORMAT_TODOS,
	NPPIDM_FORMAT_TOUNIX = IDM_FORMAT_TOUNIX,
	NPPIDM_FORMAT_TOMAC = IDM_FORMAT_TOMAC,
	NPPIDM_FORMAT_ANSI = IDM_FORMAT_ANSI,
	NPPIDM_FORMAT_UTF_8 = IDM_FORMAT_UTF_8,
	NPPIDM_FORMAT_UCS_2BE = IDM_FORMAT_UCS_2BE,
	NPPIDM_FORMAT_UCS_2LE = IDM_FORMAT_UCS_2LE,
	NPPIDM_FORMAT_AS_UTF_8 = IDM_FORMAT_AS_UTF_8,
	NPPIDM_FORMAT_CONV2_ANSI = IDM_FORMAT_CONV2_ANSI,
	NPPIDM_FORMAT_CONV2_AS_UTF_8 = IDM_FORMAT_CONV2_AS_UTF_8,
	NPPIDM_FORMAT_CONV2_UTF_8 = IDM_FORMAT_CONV2_UTF_8,
	NPPIDM_FORMAT_CONV2_UCS_2BE = IDM_FORMAT_CONV2_UCS_2BE,
	NPPIDM_FORMAT_CONV2_UCS_2LE = IDM_FORMAT_CONV2_UCS_2LE,
	NPPIDM_FORMAT_ENCODE = IDM_FORMAT_ENCODE,
	NPPIDM_FORMAT_WIN_1250 = IDM_FORMAT_WIN_1250,
	NPPIDM_FORMAT_WIN_1251 = IDM_FORMAT_WIN_1251,
	NPPIDM_FORMAT_WIN_1252 = IDM_FORMAT_WIN_1252,
	NPPIDM_FORMAT_WIN_1253 = IDM_FORMAT_WIN_1253,
	NPPIDM_FORMAT_WIN_1254 = IDM_FORMAT_WIN_1254,
	NPPIDM_FORMAT_WIN_1255 = IDM_FORMAT_WIN_1255,
	NPPIDM_FORMAT_WIN_1256 = IDM_FORMAT_WIN_1256,
	NPPIDM_FORMAT_WIN_1257 = IDM_FORMAT_WIN_1257,
	NPPIDM_FORMAT_WIN_1258 = IDM_FORMAT_WIN_1258,
	NPPIDM_FORMAT_ISO_8859_1 = IDM_FORMAT_ISO_8859_1,
	NPPIDM_FORMAT_ISO_8859_2 = IDM_FORMAT_ISO_8859_2,
	NPPIDM_FORMAT_ISO_8859_3 = IDM_FORMAT_ISO_8859_3,
	NPPIDM_FORMAT_ISO_8859_4 = IDM_FORMAT_ISO_8859_4,
	NPPIDM_FORMAT_ISO_8859_5 = IDM_FORMAT_ISO_8859_5,
	NPPIDM_FORMAT_ISO_8859_6 = IDM_FORMAT_ISO_8859_6,
	NPPIDM_FORMAT_ISO_8859_7 = IDM_FORMAT_ISO_8859_7,
	NPPIDM_FORMAT_ISO_8859_8 = IDM_FORMAT_ISO_8859_8,
	NPPIDM_FORMAT_ISO_8859_9 = IDM_FORMAT_ISO_8859_9,
	NPPIDM_FORMAT_ISO_8859_10 = IDM_FORMAT_ISO_8859_10,
	NPPIDM_FORMAT_ISO_8859_11 = IDM_FORMAT_ISO_8859_11,
	NPPIDM_FORMAT_ISO_8859_13 = IDM_FORMAT_ISO_8859_13,
	NPPIDM_FORMAT_ISO_8859_14 = IDM_FORMAT_ISO_8859_14,
	NPPIDM_FORMAT_ISO_8859_15 = IDM_FORMAT_ISO_8859_15,
	NPPIDM_FORMAT_ISO_8859_16 = IDM_FORMAT_ISO_8859_16,
	NPPIDM_FORMAT_DOS_437 = IDM_FORMAT_DOS_437,
	NPPIDM_FORMAT_DOS_720 = IDM_FORMAT_DOS_720,
	NPPIDM_FORMAT_DOS_737 = IDM_FORMAT_DOS_737,
	NPPIDM_FORMAT_DOS_775 = IDM_FORMAT_DOS_775,
	NPPIDM_FORMAT_DOS_850 = IDM_FORMAT_DOS_850,
	NPPIDM_FORMAT_DOS_852 = IDM_FORMAT_DOS_852,
	NPPIDM_FORMAT_DOS_855 = IDM_FORMAT_DOS_855,
	NPPIDM_FORMAT_DOS_857 = IDM_FORMAT_DOS_857,
	NPPIDM_FORMAT_DOS_858 = IDM_FORMAT_DOS_858,
	NPPIDM_FORMAT_DOS_860 = IDM_FORMAT_DOS_860,
	NPPIDM_FORMAT_DOS_861 = IDM_FORMAT_DOS_861,
	NPPIDM_FORMAT_DOS_862 = IDM_FORMAT_DOS_862,
	NPPIDM_FORMAT_DOS_863 = IDM_FORMAT_DOS_863,
	NPPIDM_FORMAT_DOS_865 = IDM_FORMAT_DOS_865,
	NPPIDM_FORMAT_DOS_866 = IDM_FORMAT_DOS_866,
	NPPIDM_FORMAT_DOS_869 = IDM_FORMAT_DOS_869,
	NPPIDM_FORMAT_BIG5 = IDM_FORMAT_BIG5,
	NPPIDM_FORMAT_GB2312 = IDM_FORMAT_GB2312,
	NPPIDM_FORMAT_SHIFT_JIS = IDM_FORMAT_SHIFT_JIS,
	NPPIDM_FORMAT_KOREAN_WIN = IDM_FORMAT_KOREAN_WIN,
	NPPIDM_FORMAT_EUC_KR = IDM_FORMAT_EUC_KR,
	NPPIDM_FORMAT_TIS_620 = IDM_FORMAT_TIS_620,
	NPPIDM_FORMAT_MAC_CYRILLIC = IDM_FORMAT_MAC_CYRILLIC,
	NPPIDM_FORMAT_KOI8U_CYRILLIC = IDM_FORMAT_KOI8U_CYRILLIC,
	NPPIDM_FORMAT_KOI8R_CYRILLIC = IDM_FORMAT_KOI8R_CYRILLIC,
	NPPIDM_FORMAT_ENCODE_END = IDM_FORMAT_ENCODE_END,
	NPPIDM_LANGSTYLE_CONFIG_DLG = IDM_LANGSTYLE_CONFIG_DLG,
	NPPIDM_LANG_C = IDM_LANG_C,
	NPPIDM_LANG_CPP = IDM_LANG_CPP,
	NPPIDM_LANG_JAVA = IDM_LANG_JAVA,
	NPPIDM_LANG_HTML = IDM_LANG_HTML,
	NPPIDM_LANG_XML = IDM_LANG_XML,
	NPPIDM_LANG_JS = IDM_LANG_JS,
	NPPIDM_LANG_PHP = IDM_LANG_PHP,
	NPPIDM_LANG_ASP = IDM_LANG_ASP,
	NPPIDM_LANG_CSS = IDM_LANG_CSS,
	NPPIDM_LANG_PASCAL = IDM_LANG_PASCAL,
	NPPIDM_LANG_PYTHON = IDM_LANG_PYTHON,
	NPPIDM_LANG_PERL = IDM_LANG_PERL,
	NPPIDM_LANG_OBJC = IDM_LANG_OBJC,
	NPPIDM_LANG_ASCII = IDM_LANG_ASCII,
	NPPIDM_LANG_TEXT = IDM_LANG_TEXT,
	NPPIDM_LANG_RC = IDM_LANG_RC,
	NPPIDM_LANG_MAKEFILE = IDM_LANG_MAKEFILE,
	NPPIDM_LANG_INI = IDM_LANG_INI,
	NPPIDM_LANG_SQL = IDM_LANG_SQL,
	NPPIDM_LANG_VB = IDM_LANG_VB,
	NPPIDM_LANG_BATCH = IDM_LANG_BATCH,
	NPPIDM_LANG_CS = IDM_LANG_CS,
	NPPIDM_LANG_LUA = IDM_LANG_LUA,
	NPPIDM_LANG_TEX = IDM_LANG_TEX,
	NPPIDM_LANG_FORTRAN = IDM_LANG_FORTRAN,
	NPPIDM_LANG_BASH = IDM_LANG_BASH,
	NPPIDM_LANG_FLASH = IDM_LANG_FLASH,
	NPPIDM_LANG_NSIS = IDM_LANG_NSIS,
	NPPIDM_LANG_TCL = IDM_LANG_TCL,
	NPPIDM_LANG_LISP = IDM_LANG_LISP,
	NPPIDM_LANG_SCHEME = IDM_LANG_SCHEME,
	NPPIDM_LANG_ASM = IDM_LANG_ASM,
	NPPIDM_LANG_DIFF = IDM_LANG_DIFF,
	NPPIDM_LANG_PROPS = IDM_LANG_PROPS,
	NPPIDM_LANG_PS = IDM_LANG_PS,
	NPPIDM_LANG_RUBY = IDM_LANG_RUBY,
	NPPIDM_LANG_SMALLTALK = IDM_LANG_SMALLTALK,
	NPPIDM_LANG_VHDL = IDM_LANG_VHDL,
	NPPIDM_LANG_CAML = IDM_LANG_CAML,
	NPPIDM_LANG_KIX = IDM_LANG_KIX,
	NPPIDM_LANG_ADA = IDM_LANG_ADA,
	NPPIDM_LANG_VERILOG = IDM_LANG_VERILOG,
	NPPIDM_LANG_AU3 = IDM_LANG_AU3,
	NPPIDM_LANG_MATLAB = IDM_LANG_MATLAB,
	NPPIDM_LANG_HASKELL = IDM_LANG_HASKELL,
	NPPIDM_LANG_INNO = IDM_LANG_INNO,
	NPPIDM_LANG_CMAKE = IDM_LANG_CMAKE,
	NPPIDM_LANG_YAML = IDM_LANG_YAML,
	NPPIDM_LANG_COBOL = IDM_LANG_COBOL,
	NPPIDM_LANG_D = IDM_LANG_D,
	NPPIDM_LANG_GUI4CLI = IDM_LANG_GUI4CLI,
	NPPIDM_LANG_POWERSHELL = IDM_LANG_POWERSHELL,
	NPPIDM_LANG_R = IDM_LANG_R,
	NPPIDM_LANG_JSP = IDM_LANG_JSP,
	NPPIDM_LANG_EXTERNAL = IDM_LANG_EXTERNAL,
	NPPIDM_LANG_EXTERNAL_LIMIT = IDM_LANG_EXTERNAL_LIMIT,
	NPPIDM_LANG_USER = IDM_LANG_USER,
	NPPIDM_LANG_USER_LIMIT = IDM_LANG_USER_LIMIT,
	NPPIDM_HOMESWEETHOME = IDM_HOMESWEETHOME,
	NPPIDM_PROJECTPAGE = IDM_PROJECTPAGE,
	NPPIDM_ONLINEHELP = IDM_ONLINEHELP,
	NPPIDM_FORUM = IDM_FORUM,
	NPPIDM_PLUGINSHOME = IDM_PLUGINSHOME,
	NPPIDM_UPDATE_NPP = IDM_UPDATE_NPP,
	NPPIDM_WIKIFAQ = IDM_WIKIFAQ,
	NPPIDM_HELP = IDM_HELP,
	NPPIDM_SETTING_TAB_SIZE = IDM_SETTING_TAB_SIZE,
	NPPIDM_SETTING_TAB_REPLCESPACE = IDM_SETTING_TAB_REPLCESPACE,
	NPPIDM_SETTING_HISTORY_SIZE = IDM_SETTING_HISTORY_SIZE,
	NPPIDM_SETTING_EDGE_SIZE = IDM_SETTING_EDGE_SIZE,
	NPPIDM_SETTING_IMPORTPLUGIN = IDM_SETTING_IMPORTPLUGIN,
	NPPIDM_SETTING_IMPORTSTYLETHEMS = IDM_SETTING_IMPORTSTYLETHEMS,
	NPPIDM_SETTING_TRAYICON = IDM_SETTING_TRAYICON,
	NPPIDM_SETTING_SHORTCUT_MAPPER = IDM_SETTING_SHORTCUT_MAPPER,
	NPPIDM_SETTING_REMEMBER_LAST_SESSION = IDM_SETTING_REMEMBER_LAST_SESSION,
	NPPIDM_SETTING_PREFERECE = IDM_SETTING_PREFERECE,
	NPPIDM_SETTING_AUTOCNBCHAR = IDM_SETTING_AUTOCNBCHAR,
	NPPIDM_SYSTRAYPOPUP_ACTIVATE = IDM_SYSTRAYPOPUP_ACTIVATE,
	NPPIDM_SYSTRAYPOPUP_NEWDOC = IDM_SYSTRAYPOPUP_NEWDOC,
	NPPIDM_SYSTRAYPOPUP_NEW_AND_PASTE = IDM_SYSTRAYPOPUP_NEW_AND_PASTE,
	NPPIDM_SYSTRAYPOPUP_OPENFILE = IDM_SYSTRAYPOPUP_OPENFILE,
	NPPIDM_SYSTRAYPOPUP_CLOSE = IDM_SYSTRAYPOPUP_CLOSE
};


class NotepadPlusWrapper
{
public:
	NotepadPlusWrapper(HINSTANCE hInst, HWND nppHandle);
	~NotepadPlusWrapper();

	void notify(SCNotification *notifyCode);
	
	void newDocument();
	void newDocumentWithFilename(const char *filename);

	void save();
	void saveAs(const char *filename);
	void saveAsCopy(const char *filename);

	void open(const char *filename);

	bool activateFile(const char *filename);
	int getCurrentView();
	LangType getCurrentLangType();
	void setCurrentLangType(LangType lang);

	
	boost::python::list getFiles();
	
	
	boost::python::list getSessionFiles(const char *sessionFilename);
	
	void saveSession(const char *sessionFilename, boost::python::list files);
	void saveCurrentSession(const char *filename);
	
	ScintillaWrapper createScintilla();
	void destroyScintilla(ScintillaWrapper& buffer);

	
	int getCurrentDocIndex(int view);

	void setStatusBar(StatusBarSection section, const char *text);
	long getPluginMenuHandle();

	void activateIndex(int view, int index);
	
	void activateBufferID(int bufferID);

	void loadSession(boost::python::str filename);
	
	void activateFileString(str filename);

	void reloadFile(str filename, bool withAlert);

	void saveAllFiles();

	void setFilename(const char *filename);

	boost::python::str getPluginConfigDir();

	
	
	void menuCommand(int commandID);

	
	boost::python::tuple getVersion();

	void hideTabBar();

	void showTabBar();

	bool isTabBarShown();

	int getCurrentBufferID();
	
	void reloadBuffer(int bufferID, bool withAlert = true);
	
	LangType getLangType();

	LangType getBufferLangType(int bufferID);

	void setLangType(LangType language);

	void setBufferLangType(LangType lang, int bufferID);

	BufferEncoding getEncoding();

	BufferEncoding getBufferEncoding(int bufferID);

	void setEncoding(BufferEncoding encoding);
	
	void setBufferEncoding(BufferEncoding encoding, int bufferID);
	
	FormatType getFormatType();

	FormatType getBufferFormatType(int bufferID);

	void setFormatType(FormatType format);

	void setBufferFormatType(FormatType format, int bufferID);
	
	void closeDocument();

	void closeAllDocuments();

	void closeAllButCurrentDocument();

	void reloadCurrentDocument();

	int messageBox(const char *message, const char *title, int flags);


	boost::python::object prompt(boost::python::object promptObj, boost::python::object title, boost::python::object initial);
	boost::python::object promptDefault(boost::python::object promptObj, boost::python::object title)
		{ return prompt(promptObj, title, object()); };

	boost::python::str NotepadPlusWrapper::getCurrentFilename();

	bool runPluginCommand(boost::python::str pluginName, boost::python::str menuOption);
	bool runMenuCommand(boost::python::str menuName, boost::python::str menuOption);

	bool callback(PyObject* callback, boost::python::list events);
	
	void clearAllCallbacks();
	void clearCallbackFunction(PyObject* callback);
	void clearCallbackEvents(boost::python::list events);
	void clearCallback(PyObject* callback, boost::python::list events);

protected:
	LRESULT callNotepad(UINT message, WPARAM wParam = 0, LPARAM lParam = 0)
	{
		return SendMessage(m_nppHandle, message, wParam, lParam);
	}

private:
	HWND m_nppHandle;
	HINSTANCE m_hInst;
	typedef std::multimap<int, PyObject*> callbackT;
	callbackT m_callbacks;
	bool m_notificationsEnabled;
	
};





#endif
