#include <assert.h>             // Assertion for truth testing
#include <ctype.h>              // Characters typing methods
#include <errno.h>              // Error handling
#include <dirent.h>             // Working with directories and files
#include <fenv.h>               // File environment handling
#include <float.h>              // Float conversion (more spesific)
#include <locale.h>             // Limitations per data types
#include <limits.h>             // Limitations per data types
#include <math.h>               // Mathematical functions
#include <stdbool.h>            // Standard boolean values handling
#include <stddef.h>             // Standard definitions for certain types
#include <stdint.h>             // Standard integers handling (more spesific)
#include <stdio.h>              // Standard stream handling
#include <stdlib.h>             // Standard library (more spesific)
#include <signal.h>             // Signal handling for future better runtime experience
#include <string.h>             // String manipulation and handling
#include <time.h>               // Time conversion
#include <uchar.h>              // Character conversion (U type conversion)
#include <unistd.h>             // Giving POSIX syntaxes operating system API
#include <wchar.h>              // Wide character conversion (W type conversion)
#include <wctype.h>             // Wide character typing method (String type conversion)

// #include <gtk-4.0/gtk/gtk.h>    // GTK-4.0+ Application Implementation
// #include <conio.h>              // Windows handling compatibility
// #include <raylib.h>             // Raylib library to display graphs and more
// #include <SDL2/SDL.h>           // SDL2 library to support more with Raylib
// #include <windows.h>            // Windows header file (apps and notifications)

/*
DEFINE::FDBufferSIZE
Usage:  Used for setting a certain spesific FDBuffer for
        spesific variables that might have to work with
        more than just a basic variables (pointers,
        structs, and more).
*/
#define BUFSIZE07   128         // 2^7  FDBuffer size (min. defined)
#define BUFSIZE08   256         // 2^8  FDBuffer size
#define BUFSIZE09   512         // 2^9  FDBuffer size
#define BUFSIZE10   1024        // 2^10 FDBuffer size
#define BUFSIZE11   2048        // 2^11 FDBuffer size
#define BUFSIZE12   4096        // 2^12 FDBuffer size
#define BUFSIZE13   8192        // 2^13 FDBuffer size
#define BUFSIZE14   16384       // 2^14 FDBuffer size
#define BUFSIZE15   32768       // 2^15 FDBuffer size
#define BUFSIZE16   65536       // 2^16 FDBuffer size (max. defined)
#define ENCRYPTCODE 64962

/*
DEFINE::ARROWKEYWORD
Usage:  For more safe-choice input session, so the user
        can't make any rousy inputs that can interrupt
        the whole core of the app functionality by some
        unexpected errors or bugs.
*/
#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_RIGHT   77
#define KEY_LEFT    75
#define KEY_ENTER   '\r'
#define KEY_ESC     27

/*
DEFINE::DEFINITIVEHISTOGRAM
Usage:  Used for generating a histogram from (y -> x)
        because of the exhaustive printing if done in
        (x -> y) format.
*/
#define SQUARE_BAR "\u2B1C"

/*
DEFINE::ANSICOLORFONTMODE
Usage:  Creating a spesific colored font to highlight the
        ARROWKEYWORD defining session for helping the user
        to know spesifically the choice they're on while
        in the restricted input mode.
        
Unicode Reference Link: http://www.unicode.org/
*/
#define ANSI_COLOR_RESET           "\x1b[0;0m"
#define ANSI_COLOR_DARKGRAY        "\x1b[0;30m"
#define ANSI_COLOR_RED             "\x1b[0;38;5;196m"
#define ANSI_COLOR_GREEN           "\x1b[0;38;5;82m"
#define ANSI_COLOR_YELLOW          "\x1b[0;38;5;220m"
#define ANSI_COLOR_BLUE            "\x1b[0;38;5;33m"
#define ANSI_COLOR_MAGENTA         "\x1b[0;38;5;207m"
#define ANSI_COLOR_PURPLE          "\x1b[0;38;5;93m"
#define ANSI_COLOR_CYAN            "\x1b[0;38;5;81m"
#define ANSI_COLOR_PINK            "\x1b[0;38;5;206m"
#define ANSI_COLOR_ORANGE          "\x1b[0;38;5;208m"
#define ANSI_COLOR_WHITE           "\x1b[0;37m"
#define ANSI_COLOR_LIGHTRESET      "\x1b[1;0m"
#define ANSI_COLOR_LIGHTGRAY       "\x1b[1;30m"
#define ANSI_COLOR_LIGHTRED        "\x1b[1;38;5;196m"
#define ANSI_COLOR_LIGHTGREEN      "\x1b[1;38;5;82m"
#define ANSI_COLOR_LIGHTYELLOW     "\x1b[1;38;5;220m"
#define ANSI_COLOR_LIGHTBLUE       "\x1b[1;38;5;33m"
#define ANSI_COLOR_LIGHTMAGENTA    "\x1b[1;38;5;207m"
#define ANSI_COLOR_LIGHTPURPLE     "\x1b[1;38;5;93m"
#define ANSI_COLOR_LIGHTCYAN       "\x1b[1;38;5;81m"
#define ANSI_COLOR_LIGHTWHITE      "\x1b[1;37m"
#define ANSI_COLOR_LIGHTORANGE     "\x1b[1;38;5;208m"
#define ANSI_COLOR_LIGHTPINK       "\x1b[1;38;5;206m"
#define ANSI_STYLE_BOLD            "\x1b[1m"
#define ANSI_STYLE_FAINT           "\x1b[2m"
#define ANSI_STYLE_ITALIC          "\x1b[3m"
#define ANSI_STYLE_UNDERLINE       "\x1b[4m"
#define ANSI_STYLE_BLINK           "\x1b[5m"
#define ANSI_STYLE_NEGATIVE        "\x1b[7m"
#define ANSI_STYLE_CROSSED         "\x1b[9m"

/* COLOR HIGHLIGHTING FOR MAIN MENU ONLY */
#define BRIGHTGREEN154             "\x1b[0;38;5;154m"
#define BRIGHTGREEN155             "\x1b[0;38;5;155m"
#define BRIGHTGREEN156             "\x1b[0;38;5;156m"
#define BRIGHTBLUE157              "\x1b[0;38;5;157m"
#define BRIGHTBLUE158              "\x1b[0;38;5;158m"
#define BRIGHTBLUE159              "\x1b[0;38;5;159m"

#define BRIGHTRED216               "\x1b[0;38;5;216m"
#define BRIGHTMAGENTA217           "\x1b[0;38;5;217m"
#define BRIGHTPURPLE218            "\x1b[0;38;5;218m"
#define BRIGHTPINK219              "\x1b[0;38;5;219m"

#define BRIGHTRED208               "\x1b[0;38;5;208m"
#define BRIGHTRED209               "\x1b[0;38;5;209m"
#define BRIGHTMAGENTA210           "\x1b[0;38;5;210m"
#define BRIGHTMAGENTA211           "\x1b[0;38;5;211m"
#define BRIGHTPURPLE212            "\x1b[0;38;5;212m"
#define BRIGHTPURPLE213            "\x1b[0;38;5;213m"

/*
DEFINE::FILENAMES
Usage:  Used to only be a constant file namings.
*/
#define Admin_Kemenkeu             "Kemenkeu.txt"
#define User_KepalaDaerah          "KepalaDaerah.txt"
#define Client_SektorIndustri      "SektorIndustri.txt"
#define AdminCartStore_Keranjang   "KeranjangKemenkeu.txt"
#define UserCartStore_Keranjang    "KeranjangKepalaDaerah.txt"

// ClearScreen() method, works for both Windows and UNIX.
void ClearScreen(void) {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
    #error "ERROR: Unsupported platform for performing clear screen!"
#endif
}

void EncryptTextFile(const char*, const char*, int, bool);
void DecryptTextFile(const char*, bool, int, char*);
void OverWriteStringAtLine(const char*, const char*, const int, intmax_t);
int  FindOccurences(const char*, char);
int  CountBufferEOF(const char*);
char *TrimWhiteSpaces(char*);
char *StringUppercase(char*);
char *StringLowercase(char*);
char *StringCapitalize(char*);
char *ReadLine(const char*, intmax_t);

void HomeMenu(void);
void AdminLobbyMenu(void);
void UserLobbyMenu(void);
void ClientLobbyMenu(void);

void AdminMainMenu(void);
void AMMFeature01(void);
void AMMFeature02(void);
void AMMFeature03(void);
void AMMFeature04(void);
void AMMFeature05(void);
void AMMFeature06(void);

void UserMainMenu(void);
void UMMFeature01(void);
void UMMFeature02(void);
void UMMFeature03(void);
void UMMFeature04(void);

void ClientMainMenu(void);
void CMMFeature01(void);
void CMMFeature02(void);
void CMMFeature03(void);

/*
Declaration: char *TrimWhiteSpaces(char*)
:: Trim any `leading` and `trailing` spaces, but not in the middle.
:: If encounter `all spaces`, return an empty null-terminated string.
*/
char *TrimWhiteSpaces(char* SourceString) {
    char *EndString;

    while (isspace((unsigned char)*SourceString)) SourceString++;   // Trim leading space
    if (*SourceString == 0) return SourceString;                    // All spaces?
    EndString = SourceString + strlen(SourceString) - 1;            // Trim trailing space
    while (EndString > SourceString && isspace((unsigned char)*EndString)) EndString--;

    EndString[1] = '\0'; // Write new null terminator character
    return SourceString;
}

/*
Declaration: char *ReadLine(const char*, intmax_t)
:: Read the whole `Line` within the `SourceTextFile`, including the latest newline character `\n`.
:: The `SourceTextFile` doesn't have to be opened by the `FILE` struct pointer, since it will be
opened inside the function automatically.
*/
char *ReadLine(const char* SourceTextFile, intmax_t Line) {
    FILE *FSource = fopen(SourceTextFile, "r");
    char FDBuffer[BUFSIZE10], *ReturnFDBuffer = malloc(BUFSIZE10);
    intmax_t Lines = 0;
    
    do {
        if (++Lines == Line) {
            fgets(FDBuffer, BUFSIZE10, FSource);
            break;
        }
    } while((fscanf(FSource, "%*[^\n]"), fscanf(FSource, "%*c")) != EOF);
    if (Lines == Line) { strcpy(ReturnFDBuffer, FDBuffer); fclose(FSource); return ReturnFDBuffer; }
    fclose(FSource); return ReturnFDBuffer;
}

/*
void OverWriteStringAtLine(const char*, const char*, const int, intmax_t)
:: Specifically over-writing a given line from a new given string, including newline character at EOF `\n`.
:: Hence, no need to insert extra `\n` in the given string, unless it's done intentionlally.
:: CUSTOM: `EncryptionKey` leaves at 0 if you don't want to encode the new written line on the text file.
*/
void OverWriteStringAtLine(const char* FSourceTxtFile, const char* NewOverWriteString, const int EncryptionKey, intmax_t AtSpesificLine) {
	FILE *FSource, *FDestination, *FCopyAndDecrypting, *FTempDestination;
	intmax_t AtLine = AtSpesificLine, LineControl = 0, BufLen = 0;
	char FDBuffer[BUFSIZE16], NewlyString[BUFSIZE16], FileName[BUFSIZE10];      
	char OverWriteStringLine[BUFSIZE16], FTempDestinationTxtFile[BUFSIZE07] = "TempDestination.txt", DeleteTempDestinationTxtFile[BUFSIZE07];
	
	FCopyAndDecrypting = fopen(FSourceTxtFile, "r");
	FTempDestination   = fopen("FTempDestination.txt", "w");
	while (fgets(FDBuffer, sizeof(FDBuffer), FCopyAndDecrypting) != 0) {
		BufLen = strlen(FDBuffer);
		for (intmax_t i = 0; i < BufLen; i++) FDBuffer[i] += EncryptionKey;
		fputs(FDBuffer, FTempDestination);
	} fclose(FCopyAndDecrypting); fclose(FTempDestination);

	strncpy(FileName, FSourceTxtFile, BUFSIZE10);
	FSource      = fopen("FTempDestination.txt", "r");
	FDestination = fopen(FTempDestinationTxtFile, "w");

	strncpy(OverWriteStringLine, NewOverWriteString, BUFSIZE16);
	strcat(OverWriteStringLine, "\n");

	while (!feof(FSource)) {
		strcpy(NewlyString, "\0");
		fgets(NewlyString, BUFSIZE16, FSource);

		if (!feof(FSource))  {
			LineControl++;
			if (LineControl != AtLine) { fputs(NewlyString, FDestination); }
			else { fputs(OverWriteStringLine, FDestination); }
		}
	} fclose(FSource);
	fclose(FDestination);
	remove(FileName); rename(FTempDestinationTxtFile, FileName);

    strcpy(DeleteTempDestinationTxtFile, "del ");
    strcat(DeleteTempDestinationTxtFile, "FTempDestination.txt");
    system(DeleteTempDestinationTxtFile);
}

char *StringUppercase(char* SourceString) {
    for (int i = 0; SourceString[i] != '\0'; i++) {
        if (SourceString[i] >= 'a' && SourceString[i] <= 'z') SourceString[i] -= 32;
    } return SourceString;
}

char *StringLowercase(char* SourceString) {
    for (int i = 0; SourceString[i] != '\0'; i++) {
        if (SourceString[i] >= 'A' && SourceString[i] <= 'Z') SourceString[i] += 32;
    } return SourceString;
}

char *StringCapitalize(char* SourceString) {
    for (int i = 0; SourceString[i] != '\0'; i++) {
        if (SourceString[0] >= 'A' && SourceString[0] <= 'Z') NULL;
        if (SourceString[0] >= 'a' && SourceString[0] <= 'z') SourceString[0] -= 32;
        if (i != 0 && (SourceString[i] >= 'A' && SourceString[i] <= 'Z')) SourceString[i] += 32;
        if (i != 0 && (SourceString[i] >= 'a' && SourceString[i] <= 'z')) NULL;
    } return SourceString;
}

int FindOccurences(const char* SourceString, char SearchedOccurence) {
    int CountOccurences;
    for (int i = 0; (long long unsigned int)i < strlen(SourceString) - 1; i++) {
        if (SourceString[i] == SearchedOccurence) CountOccurences++;
    } return CountOccurences;
}

int CountBufferEOF(const char* SourceString) {
    FILE *FSource = fopen(SourceString, "r");
    int Lines = 0;
    
    while((fscanf(FSource, "%*[^\n]"), fscanf(FSource, "%*c")) != EOF) { Lines++; }
    Lines++; fclose(FSource); return Lines;
}

void EncryptTextFile(const char* SourceTextFile, const char* DestinationTextFile, int EncryptionKey, bool SourceTextFileDeletion) {
    FILE *FSource, *FDestination;
    int BufLen;
    char FDBuffer[BUFSIZE16], DeleteSourceTxtFile[BUFSIZE07];

    FSource      = fopen(SourceTextFile, "r");
    FDestination = fopen(DestinationTextFile, "w");
    while (fgets(FDBuffer, sizeof(FDBuffer), FSource) != 0) {
        BufLen = strlen(FDBuffer);
        for (int i = 0; i < BufLen; i++) FDBuffer[i] -= EncryptionKey;
        fputs(FDBuffer, FDestination);
    }
    fclose(FSource); fclose(FDestination);

    if (SourceTextFileDeletion) {
        strcpy(DeleteSourceTxtFile, "del ");
        strcat(DeleteSourceTxtFile, SourceTextFile);
        system(DeleteSourceTxtFile);
    }
}

void DecryptTextFile(const char* DestinationTextFile, bool ReadDecryptedFile, int DecryptionKey, char* ReadByFileNameAndKeys) {
    FILE *FDestination, *FTempDestination;
    int BufLen, Ptr = 0, KeyTracker = 0, LineTracker = 0, FTDPos = 0;
    char C, FDBuffer[BUFSIZE10], DeleteTempDestinationTxtFile[BUFSIZE07], TxtFileName[BUFSIZE07];
    char *SourceTextFileName, *SourceKeyStringValue, *SelectedKeyString;
    char *SourceKeyStringValues[BUFSIZE10], FTDestination[BUFSIZE10][BUFSIZE10], ReadDecryptedKeyString[BUFSIZE10];

    if (ReadDecryptedFile) {
        FDestination = fopen(DestinationTextFile, "r");
        while (fgets(FDBuffer, sizeof(FDBuffer), FDestination) != 0) {
            BufLen = strlen(FDBuffer);
            for (int i = 0; i < BufLen; i++) FDBuffer[i] += DecryptionKey;
            fputs(FDBuffer, stdout);
        } fclose(FDestination);
    }

    if (ReadByFileNameAndKeys != NULL) {
        FDestination     = fopen(DestinationTextFile, "r");
        FTempDestination = fopen("TempDestination.txt", "w");

        while (fgets(FDBuffer, sizeof(FDBuffer), FDestination) != 0) {
            BufLen = strlen(FDBuffer);
            for (int i = 0; i < BufLen; i++) FDBuffer[i] += DecryptionKey;
            fputs(FDBuffer, FTempDestination);
        } fclose(FDestination); fclose(FTempDestination);

        strcpy(ReadDecryptedKeyString, ReadByFileNameAndKeys);
        strcpy(TxtFileName, ReadDecryptedKeyString);
        strtok_r(TxtFileName, ">", &SelectedKeyString);
        SelectedKeyString = TrimWhiteSpaces(SelectedKeyString);
        SourceKeyStringValue = strtok(SelectedKeyString, ",");
        KeyTracker++;

        while (SourceKeyStringValue != NULL) {
            SourceKeyStringValues[Ptr] = SourceKeyStringValue;
            SourceKeyStringValues[Ptr] = TrimWhiteSpaces(SourceKeyStringValues[Ptr]);
            SourceKeyStringValue = strtok(NULL, ",");
            Ptr++; KeyTracker++;
        } SourceTextFileName = TrimWhiteSpaces(TxtFileName);
        
        if (strcmp(SourceTextFileName, DestinationTextFile) == 0) {
            if ((strchr(TxtFileName, ':') == NULL) && (strchr(SelectedKeyString, ':') == NULL)) {
                int FTDIndex = 0, SKSVIndex = 0;

                FDestination = fopen("TempDestination.txt", "r");
                for (C = getc(FDestination); C != EOF; C = getc(FDestination))
                    if (C == '\n') LineTracker++;
                fclose(FDestination);

                FDestination = fopen("TempDestination.txt", "r");
                while(fgets(FTDestination[FTDPos], BUFSIZE10, FDestination) != NULL) {
                    if (FTDPos < LineTracker)
                        FTDestination[FTDPos][strlen(FTDestination[FTDPos]) - 1] = '\0';
                    FTDPos++;
                } fclose(FDestination);

                while (FTDIndex <= LineTracker) {
                    while (SKSVIndex <= KeyTracker - 2) {
                        if (strstr(FTDestination[FTDIndex], SourceKeyStringValues[SKSVIndex]) != NULL) {
                            printf("%s\n", FTDestination[FTDIndex]); break;
                        } else if (strstr(FTDestination[FTDIndex], SourceKeyStringValues[SKSVIndex]) == NULL)
                            SKSVIndex++;
                    } FTDIndex++; SKSVIndex = 0;
                }
                strcpy(DeleteTempDestinationTxtFile, "del ");
                strcat(DeleteTempDestinationTxtFile, "TempDestination.txt");
                system(DeleteTempDestinationTxtFile);
            }
        } else {
            strcpy(DeleteTempDestinationTxtFile, "del ");
            strcat(DeleteTempDestinationTxtFile, "TempDestination.txt");
            system(DeleteTempDestinationTxtFile);
        }
    }
}

FILE *Admin, *User, *Client, *AdminCart, *UserCart;

typedef struct Admin {
    const char *Username, *Password;
    char *StateTaxes, *StateSavings;
    char SignInUsername[BUFSIZE07], SignInPassword[BUFSIZE07];
    int Status;
} Kemenkeu;

typedef struct User {
    char FullName[BUFSIZE07], NIK[32], Email[BUFSIZE07], Password[32];
    char BirthPlaceDate[BUFSIZE07], JobTitle[BUFSIZE07], HeadRegion[BUFSIZE07];
} KepalaDaerah;

typedef struct Client {
    char FullName[BUFSIZE07], IndustryName[BUFSIZE07], Username[BUFSIZE07], Password[32];
} SektorIndustri;

typedef struct CartStore {
    int Status;
    char Requester[BUFSIZE07], Accepter[BUFSIZE07], ProductInDemand[BUFSIZE07];
} Keranjang;

/* Function-like-macro Definitions */
int Continuing = 0, CountRegists = 1, RSOption = -1; // User&Client-defined RSOption
bool CheckInvalidInput = false, CheckSuccessInput = false, SuccessfullyLoggedIn = false;
#define AcceptInputOption(Message, Variable) fflush(stdin); printf((Message)); scanf("%d", &(Variable)); fflush(stdin);
#define AcceptCharInput(Message, Variable) fflush(stdin); printf((Message)); scanf("%c", &(Variable)); fflush(stdin);
#define AcceptInputText(Message, Variable) fflush(stdin); printf((Message)); fgets((Variable), sizeof((Variable)), stdin); fflush(stdin);
#define AcceptLL(Message, Variable) fflush(stdin); printf((Message)); scanf("%lld", &(Variable)); fflush(stdin);
#define AcceptF(Message, Variable) fflush(stdin); printf((Message)); scanf("%f", &(Variable)); fflush(stdin);

Kemenkeu AdminSignIn = { 0 };
void WritePrivateKemenkeu(bool _ReadWithCaution) {
    if (_ReadWithCaution) { DecryptTextFile(Admin_Kemenkeu, true, ENCRYPTCODE, NULL); }
    else {
        Kemenkeu KepalaWakanda = {
                                    .Username = "D'Wakanda",
                                    .Password = "Kemenkeu2024",
                                    .StateTaxes = "0",
                                    .StateSavings = "1000000000000000",
                                    .Status = 1
                                };
        
        if (access(Admin_Kemenkeu, F_OK) != 0) {
            Admin = fopen("Temp_"Admin_Kemenkeu, "w");

            if (Admin == NULL) {
                fprintf(stderr, "ERROR: Tidak dapat menuliskan data admin Kemenkeu ke dalam file.\n");
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                HomeMenu();
            }

            fprintf(Admin, "%s\n%s\n%s\n%s\n%d\n\n", KepalaWakanda.Username, KepalaWakanda.Password, KepalaWakanda.StateTaxes, KepalaWakanda.StateSavings, KepalaWakanda.Status);
            
            fclose(Admin);
            EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);
        }
    }
}

KepalaDaerah KDSignIn = { 0 };
char KD_SignInNIK[32] = { 0 }, KD_SignInPassword[32] = { 0 };
char KDFullName[BUFSIZE07] = { 0 }, KDJobTitle[BUFSIZE07] = { 0 }, KDHeadRegion[BUFSIZE07] = { 0 };
int KDLoggedIn = 0;
void WritePublicKepalaDaerah(bool _ReadWithCaution) {
    if (_ReadWithCaution) { DecryptTextFile(User_KepalaDaerah, true, ENCRYPTCODE, NULL); }
    else {
        int RegisteredKDs = 0;
        char WrittenRegisteredKDs[BUFSIZE07], CreateKDSavings[BUFSIZE07];

        if (access(User_KepalaDaerah, F_OK) != 0) {
            User = fopen("Temp_"User_KepalaDaerah, "w");

            if (User == NULL) {
                fprintf(stderr, "ERROR: Tidak dapat menuliskan data pengguna Kepala Daerah ke dalam file.\n");
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                HomeMenu();
            }

            fprintf(User, "1\n\n");
            fprintf(User, "%s\n", KDSignIn.FullName);
            fprintf(User, "%s\n", KDSignIn.NIK);
            fprintf(User, "%s\n", KDSignIn.Email);
            fprintf(User, "%s\n", KDSignIn.Password);
            fprintf(User, "%s\n", KDSignIn.BirthPlaceDate);
            fprintf(User, "%s\n", KDSignIn.JobTitle);
            fprintf(User, "%s\n", KDSignIn.HeadRegion);
            fprintf(User, "0\n0\n0\n");
            
            fclose(User);
            EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
    
        } else {
            EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, false);
            
            RegisteredKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
            RegisteredKDs++;
            snprintf(WrittenRegisteredKDs, sizeof(WrittenRegisteredKDs), "%d", RegisteredKDs);
            OverWriteStringAtLine("Temp_"User_KepalaDaerah, WrittenRegisteredKDs, 0, 1);

            User = fopen("Temp_"User_KepalaDaerah, "a");
            fprintf(User, "\n");
            fprintf(User, "%s\n", KDSignIn.FullName);
            fprintf(User, "%s\n", KDSignIn.NIK);
            fprintf(User, "%s\n", KDSignIn.Email);
            fprintf(User, "%s\n", KDSignIn.Password);
            fprintf(User, "%s\n", KDSignIn.BirthPlaceDate);
            fprintf(User, "%s\n", KDSignIn.JobTitle);
            fprintf(User, "%s\n", KDSignIn.HeadRegion);
            fprintf(User, "0\n0\n0\n");

            fclose(User);
            EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
        }

        snprintf(CreateKDSavings, sizeof(CreateKDSavings) + 16, "KD - %s.txt", KDSignIn.FullName);
        User = fopen("Temp_NewKD.txt", "w");
        fprintf(User, "1000000000000\n\n");
        fclose(User);
        EncryptTextFile("Temp_NewKD.txt", CreateKDSavings, ENCRYPTCODE, true);
    }
}

SektorIndustri SISignIn = { 0 };
char SI_SignInUsername[BUFSIZE07] = { 0 }, SI_SignInPassword[32] = { 0 };
char SIFullName[BUFSIZE07] = { 0 }, SIIndustryName[BUFSIZE07] = { 0 };
int SILoggedIn = 0;
void WritePublicSektorIndustri(bool _ReadWithCaution) {
    if (_ReadWithCaution) { DecryptTextFile(Client_SektorIndustri, true, ENCRYPTCODE, NULL); }
    else {
        int RegisteredSIs = 0;
        char WrittenRegisteredSIs[BUFSIZE07], CreateSISavings[BUFSIZE07];

        if (access(Client_SektorIndustri, F_OK) != 0) {
            Client = fopen("Temp_"Client_SektorIndustri, "w");

            if (Client == NULL) {
                fprintf(stderr, "ERROR: Tidak dapat menuliskan data pengguna Sektor Industri ke dalam file.\n");
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                HomeMenu();
            }

            fprintf(Client, "1\n\n");
            fprintf(Client, "%s\n", SISignIn.FullName);
            fprintf(Client, "%s\n", SISignIn.IndustryName);
            fprintf(Client, "%s\n", SISignIn.Username);
            fprintf(Client, "%s\n", SISignIn.Password);
            fprintf(Client, "0\n");
            for (int _ = 0; _ < 5; _++) { fprintf(Client, "-, -, -\n"); }
            
            fclose(Client);
            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
    
        } else {
            EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, false);
            
            RegisteredSIs = atoi(ReadLine("Temp_"Client_SektorIndustri, 1));
            RegisteredSIs++;
            snprintf(WrittenRegisteredSIs, sizeof(WrittenRegisteredSIs), "%d", RegisteredSIs);
            OverWriteStringAtLine("Temp_"Client_SektorIndustri, WrittenRegisteredSIs, 0, 1);

            Client = fopen("Temp_"Client_SektorIndustri, "a");
            fprintf(Client, "\n");
            fprintf(Client, "%s\n", SISignIn.FullName);
            fprintf(Client, "%s\n", SISignIn.IndustryName);
            fprintf(Client, "%s\n", SISignIn.Username);
            fprintf(Client, "%s\n", SISignIn.Password);
            fprintf(Client, "0\n");
            for (int _ = 0; _ < 5; _++) { fprintf(Client, "-, -, -\n"); }

            fclose(Client);
            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
        }

        snprintf(CreateSISavings, sizeof(CreateSISavings) + 16, "SI - %s.txt", SISignIn.FullName);
        Client = fopen("Temp_NewSI.txt", "w");
        fprintf(Client, "0\n\n");
        fclose(Client);
        EncryptTextFile("Temp_NewSI.txt", CreateSISavings, ENCRYPTCODE, true);
    }
}

Keranjang Belanja = { 0 };
void WritePrivateKeranjang(bool WriteForAdmin, int DeleteCurrentData, bool _ReadWithCaution) {
    if (_ReadWithCaution) {
        DecryptTextFile(AdminCartStore_Keranjang, true, ENCRYPTCODE, NULL); puts("");
        DecryptTextFile(UserCartStore_Keranjang, true, ENCRYPTCODE, NULL);
    } else {
        if (WriteForAdmin) {
            if (access(AdminCartStore_Keranjang, F_OK) != 0) {
                AdminCart = fopen("Temp_"AdminCartStore_Keranjang, "w");
                fprintf(AdminCart, "0\n");
                fclose(AdminCart);
                EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);

            } else {
                char NewStoredCart[BUFSIZE07] = { 0 };

                if (DeleteCurrentData < 1) {
                    EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);

                    snprintf(NewStoredCart, sizeof(NewStoredCart), "%d", atoi(ReadLine("Temp_"AdminCartStore_Keranjang, 1)) + 1);
                    OverWriteStringAtLine("Temp_"AdminCartStore_Keranjang, NewStoredCart, 0, 1);
                    
                    AdminCart = fopen("Temp_"AdminCartStore_Keranjang, "a");
                    fprintf(AdminCart, "\n%s\n%s\n%s\n%d\n", Belanja.Requester, Belanja.Accepter, Belanja.ProductInDemand, Belanja.Status);
                    fclose(AdminCart);

                    EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);

                } else {
                    NULL;
                }
            }

        } else {
            if (access(UserCartStore_Keranjang, F_OK) != 0) {
                UserCart = fopen("Temp_"UserCartStore_Keranjang, "w");
                fprintf(UserCart, "0\n");
                fclose(UserCart);
                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

            } else {
                char NewStoredCart[BUFSIZE07] = { 0 };

                if (DeleteCurrentData < 1) {
                    EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);

                    snprintf(NewStoredCart, sizeof(NewStoredCart), "%d", atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1)) + 1);
                    OverWriteStringAtLine("Temp_"UserCartStore_Keranjang, NewStoredCart, 0, 1);
                    
                    UserCart = fopen("Temp_"UserCartStore_Keranjang, "a");
                    fprintf(UserCart, "\n%s\n%s\n%s\n%d\n", Belanja.Requester, Belanja.Accepter, Belanja.ProductInDemand, Belanja.Status);
                    fclose(UserCart);

                    EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

                } else {
                    NULL;
                }
            }
        }
    }
}

void AdminMainMenu(void) {
    int AMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AdminMainMenu();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);

    puts("");
    puts(BRIGHTGREEN156 ANSI_STYLE_ITALIC "~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"[1] Pajak dan Tabungan Negara: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengatur dan menampilkan informasi mengenai Pajak dan Tabungan Negara."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[2] Data Kepala Daerah dan Perekonomiannya: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Menampilkan informasi Kepala Daerah beserta data perekonomian tiap daerahnya."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[3] Data Sektor Industri dan Penghasilannya: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Menampilkan informasi Sektor Industri beserta beserta data penghasilannya."ANSI_COLOR_RESET);
    puts(BRIGHTBLUE159"[4] Pendistribusian Bantuan Dana: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengatur pendistribusian bantuan dana ke masing-masing Kepala Daerah."ANSI_COLOR_RESET);
    puts(BRIGHTBLUE159"[5] Pengaturan Kerja Sama dengan Kepala Daerah: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengatur kegiatan kerja sama yang tengah diajukan oleh Kepala Daerah."ANSI_COLOR_RESET);
    puts(BRIGHTBLUE159"[6] Distribusi Perdagangan Internasional: "ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengatur distribusi barang skala internasional setelah pengajuan sebelumnya."ANSI_COLOR_RESET);
    puts(ANSI_COLOR_LIGHTRED ANSI_STYLE_ITALIC"[0] Keluar... (Log Out)"ANSI_COLOR_RESET);

    puts("");
    AcceptInputOption("> Pilihan Anda: ", AMMOption)

    switch (AMMOption) {
        case 1:  { AMMFeature01(); } break;
        case 2:  { AMMFeature02(); } break;
        case 3:  { AMMFeature03(); } break;
        case 4:  { AMMFeature04(); } break;
        case 5:  { AMMFeature05(); } break;
        case 6:  { AMMFeature06(); } break;
        case 0:  { HomeMenu();     } break;
        default: { CheckInvalidInput = true; AdminMainMenu(); } break;
    }
}

void AMMFeature01(void) {
    Kemenkeu StateProfile = { 0 };
    char NewWrittenST[8] = { 0 };
    float NewST = 0.0f;
    int Options = 0;

    EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
    StateProfile.StateTaxes = ReadLine("Temp_"Admin_Kemenkeu, 3);
    StateProfile.StateSavings = ReadLine("Temp_"Admin_Kemenkeu, 4);
    EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature01();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [1] Pajak dan Tabungan Negara"ANSI_COLOR_RESET);

    puts("");
    puts("Berikut adalah hasil laporan Pajak dan Keuangan Negara:");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    printf(BRIGHTPINK219":: Pajak Negara    (~%%): %.02f%%\n", atof(StateProfile.StateTaxes));
    if (1000000000000LL - atoll(StateProfile.StateSavings) > 0LL)
         { printf(BRIGHTBLUE159":: Tabungan Negara (Rp): Rp%'lld,00 >> (-Rp%'lld,00)\n", atoll(StateProfile.StateSavings), 1000000000000LL - atoll(StateProfile.StateSavings)); }
    else { printf(BRIGHTBLUE159":: Tabungan Negara (Rp): Rp%'lld,00 >> (+Rp%'lld,00)\n", atoll(StateProfile.StateSavings), atoll(StateProfile.StateSavings) - 1000000000000LL); }
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    puts("");
    puts(BRIGHTPURPLE213 ANSI_STYLE_ITALIC"~ Apakah Anda ingin melakukan perubahan? ~"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"[1] Ubah besar Pajak Negara (%)");
    puts(BRIGHTBLUE159"[2] Lihat alur Perekonomian Negara (Rp)");
    puts(ANSI_COLOR_RED"[0] Kembali..."ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", Options);

    puts("");
    if (Options == 1) {
        AcceptF(BRIGHTGREEN156"Sertakan besar persentase pajak negara terbaru (%%): ", NewST);
        
        if (NewST < 0.0f || NewST > 100.0f) {
            puts(ANSI_COLOR_RED"ERROR: Persentase Pajak Negara harus berada dalam jangkauan 0.0% hingga 100.0%!"ANSI_COLOR_RESET);
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            AMMFeature01();
        }

        snprintf(NewWrittenST, sizeof(NewWrittenST), "%0.2f", NewST);
        OverWriteStringAtLine(Admin_Kemenkeu, NewWrittenST, ENCRYPTCODE, 3);
        EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, 0, true);
        EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

        puts(ANSI_COLOR_GREEN"Pembaruan Pajak Negara telah berhasil!"ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        AMMFeature01();
    
    } else if (Options == 2) {
        ClearScreen();
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [1] Pajak dan Tabungan Negara"ANSI_COLOR_RESET);

        puts("");
        puts("Berikut adalah hasil laporan Keuangan Negara secara keseluruhan:");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        if (1000000000000LL - atoll(StateProfile.StateSavings) > 0LL)
             { printf(BRIGHTGREEN156"Tabungan Negara (Rp): Rp%'lld.00 >> (-Rp%'lld.00)\n", atoll(StateProfile.StateSavings), 1000000000000LL - atoll(StateProfile.StateSavings)); }
        else { printf(BRIGHTGREEN156"Tabungan Negara (Rp): Rp%'lld.00 >> (+Rp%'lld.00)\n", atoll(StateProfile.StateSavings), atoll(StateProfile.StateSavings) - 1000000000000LL); }
        
        puts("");
        puts(BRIGHTBLUE159"Pemasukkan (Incomes):");
        DecryptTextFile(Admin_Kemenkeu, false, ENCRYPTCODE, Admin_Kemenkeu" > [+]"); puts("");
        puts(BRIGHTMAGENTA211"Pengeluaran (Expenses):");
        DecryptTextFile(Admin_Kemenkeu, false, ENCRYPTCODE, Admin_Kemenkeu" > [-]");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AMMFeature01();

    } else if (Options == 0) { AdminMainMenu(); }
    else                     { CheckInvalidInput = true; AMMFeature01(); }
}

void AMMFeature02(void) {
    KepalaDaerah KDList = { 0 };
    char CurrentFileKD[BUFSIZE07] = { 0 }, KDShownSavings[BUFSIZE07] = { 0 };
    char TotalSavings[BUFSIZE07] = { 0 }, KDSSPositive[BUFSIZE07] = { 0 }, KDSSNegative[BUFSIZE07] = { 0 };
    int PeekKD = 0, MaxKD = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature02();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [2] Data Perekonomian dan Kepala Daerah"ANSI_COLOR_RESET);

    if (access(User_KepalaDaerah, F_OK) != 0) {
        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        puts(ANSI_COLOR_LIGHTORANGE"Data Kepala Daerah masih kosong!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Mohon maaf, saat ini belum ada Kepala Daerah yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    }

    EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
    
    puts("");
    puts("Berikut adalah data dari seluruh Kepala Daerah yang terdaftarkan...");

    printf(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int KD = 0; KD < atoi(ReadLine("Temp_"User_KepalaDaerah, 1)); KD++) {
        MaxKD++;

        strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
        strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
        strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

        snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 16, "KD - %s.txt", KDList.FullName);
        EncryptTextFile(CurrentFileKD, "TempCFKD.txt", -ENCRYPTCODE, false);
        strcpy(KDShownSavings, ReadLine("TempCFKD.txt", 1));
        KDShownSavings[strlen(KDShownSavings) - 1] = '\0';

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);
        printf("... Perekonomian Total Daerah: Rp%'lld.00\n", atoll(KDShownSavings));

    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    system("del TempCFKD.txt");
    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
    
    puts("");
    puts(ANSI_COLOR_MAGENTA"Sertakan penomoran Kepala Daerah di atas untuk melihat data perekonomian daerah lebih lanjut!");
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, ketik angka 0 untuk kembali ke menu utama Kemenkeu)"ANSI_COLOR_RESET);
    AcceptInputOption("> Lihat data Kepala Daerah: ", PeekKD);

    if (PeekKD == 0) { AdminMainMenu(); }
    else if (PeekKD > 0 && PeekKD <= (MaxKD + 1)) {
        ClearScreen();
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [2] Data Perekonomian dan Kepala Daerah"ANSI_COLOR_RESET);

        PeekKD--;
        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
        strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 3));
        strcpy(KDList.NIK, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 4));
        strcpy(KDList.Email, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 5));
        strcpy(KDList.BirthPlaceDate, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 7));
        strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 8));
        strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * PeekKD) + 9));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';
        KDList.NIK[strlen(KDList.NIK) - 1] = '\0'; KDList.Email[strlen(KDList.Email) - 1] = '\0'; KDList.BirthPlaceDate[strlen(KDList.BirthPlaceDate) - 1] = '\0';

        snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 16, "KD - %s.txt", KDList.FullName);
        
        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"=== Data Perekonomian Kepala Daerah ===");
        printf("Yth. Kepala Dserah a.n.: %s, menjabat sebagai %s %s.\n", KDList.FullName, KDList.JobTitle, KDList.HeadRegion);
        printf(":: NIK/E-mail: %s/%s\n", KDList.NIK, KDList.Email);
        printf(":: Tempat/Tanggal Lahir: %s\n"ANSI_COLOR_RESET, KDList.BirthPlaceDate);

        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
        
        EncryptTextFile(CurrentFileKD, "TempKD.txt", -ENCRYPTCODE, false);
        strcpy(TotalSavings, ReadLine("TempKD.txt", 1));
        TotalSavings[strlen(TotalSavings) - 1] = '\0';
        snprintf(KDSSPositive, sizeof(KDSSPositive) + 9, "%s > [+]", CurrentFileKD);
        snprintf(KDSSNegative, sizeof(KDSSNegative) + 9, "%s > [-]", CurrentFileKD);
        EncryptTextFile("TempKD.txt", CurrentFileKD, ENCRYPTCODE, true);

        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        printf(BRIGHTGREEN156"Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
        puts(BRIGHTBLUE159"Pemasukkan (Incomes): ");
        DecryptTextFile(CurrentFileKD, false, ENCRYPTCODE, KDSSPositive); puts("");
        puts(BRIGHTMAGENTA211"Pengeluaran (Expenses): ");
        DecryptTextFile(CurrentFileKD, false, ENCRYPTCODE, KDSSNegative);
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        AMMFeature02();
    
    } else { CheckInvalidInput = true; AMMFeature02(); }
}

void AMMFeature03(void) {
    SektorIndustri SIList = { 0 };
    char TotalSavings[BUFSIZE07] = { 0 }, SISSPositive[BUFSIZE07] = { 0 };
    char CurrentFileSI[BUFSIZE07] = { 0 }, SIShownSavings[BUFSIZE07] = { 0 };
    int PeekSI = 0, MaxSI = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature03();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [3] Data Sektor Industri"ANSI_COLOR_RESET);

    if (access(Client_SektorIndustri, F_OK) != 0) {
        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        puts(ANSI_COLOR_LIGHTORANGE"Data Sektor Industri masih kosong!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Mohon maaf, saat ini belum ada Sektor Industri yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    }

    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
    
    puts("");
    puts("Berikut adalah data dari seluruh Sektor Industri yang terdaftarkan...");

    printf(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int SI = 0; SI < atoi(ReadLine("Temp_"Client_SektorIndustri, 1)); SI++) {
        MaxSI++;

        strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SI) + 3));
        strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SI) + 4));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

        snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 16, "SI - %s.txt", SIList.FullName);
        EncryptTextFile(CurrentFileSI, "TempCFSI.txt", -ENCRYPTCODE, false);
        strcpy(SIShownSavings, ReadLine("TempCFSI.txt", 1));
        SIShownSavings[strlen(SIShownSavings) - 1] = '\0';

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (SI + 1), SIList.FullName);
        printf("... Nama Industri: %s\n", SIList.IndustryName);
        printf("... Perekonomian Total Industri: Rp%'lld.00\n", atoll(SIShownSavings));

    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    system("del TempCFSI.txt");
    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

    puts("");
    puts(ANSI_COLOR_MAGENTA"Sertakan penomoran Sektor Industri di atas untuk melihat data perekonomian daerah lebih lanjut!");
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, ketik angka 0 untuk kembali ke menu utama Kemenkeu)"ANSI_COLOR_RESET);
    AcceptInputOption("> Lihat data Sektor Industri: ", PeekSI);

    if (PeekSI == 0) { AdminMainMenu(); }
    else if (PeekSI > 0 && PeekSI <= (MaxSI + 1)) {
        ClearScreen();
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [3] Data Sektor Industri"ANSI_COLOR_RESET);

        PeekSI--;
        EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
        strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * PeekSI) + 3));
        strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * PeekSI) + 4));
        strcpy(SIList.Username, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * PeekSI) + 5));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0'; SIList.Username[strlen(SIList.Username) - 1] = '\0';

        snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 16, "SI - %s.txt", SIList.FullName);
        
        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"=== Data Perekonomian Sektor Industri ===");
        printf("Yth. Sektor Industri, a.n.: %s, Direktur %s\n", SIList.FullName, SIList.IndustryName);
        printf(":: Kode Klien: %s\n"ANSI_COLOR_RESET, SIList.Username);
        EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

        EncryptTextFile(CurrentFileSI, "TempSI.txt", -ENCRYPTCODE, false);
        strcpy(TotalSavings, ReadLine("TempSI.txt", 1));
        TotalSavings[strlen(TotalSavings) - 1] = '\0';
        snprintf(SISSPositive, sizeof(SISSPositive) + 9, "%s > [+]", CurrentFileSI);
        EncryptTextFile("TempSI.txt", CurrentFileSI, ENCRYPTCODE, true);

        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        printf(BRIGHTGREEN156"Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
        puts(BRIGHTBLUE159"Pemasukkan (Incomes): ");
        DecryptTextFile(CurrentFileSI, false, ENCRYPTCODE, SISSPositive); puts("");
        puts(BRIGHTMAGENTA211"Pengeluaran (Expenses): TIDAK ADA PENGELUARAN UNTUK SEKTOR INDUSTRI");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        AMMFeature03();
    
    } else { CheckInvalidInput = true; AMMFeature03(); }
}

void AMMFeature04(void) {
    FILE *AccessAdmin;
    KepalaDaerah KDList = { 0 };

    long long int GivenNomina = 0LL;
    char KDFileName[BUFSIZE07] = { 0 };
    char UpdateStatus, WriteString01_A[BUFSIZE07] = { 0 }, WriteString02_U[BUFSIZE07] = { 0 }, WriteString03_U[BUFSIZE07] = { 0 };
    char GetKDFullName[BUFSIZE07] = { 0 }, GetKDJobTitle[BUFSIZE07] = { 0 }, GetKDHeadRegion[BUFSIZE07] = { 0 };
    int StatusList[BUFSIZE10] = { 0 };
    int AvailableKDs = 0, RecentStatus = 0, PeekKD = 0, MaxKD = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature04();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [4] Pendistribusian Bantuan Dana"ANSI_COLOR_RESET);

    if (access(User_KepalaDaerah, F_OK) != 0) {
        puts("");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        puts(ANSI_COLOR_LIGHTORANGE"Data Kepala Daerah masih kosong!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Mohon maaf, saat ini belum ada Kepala Daerah yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    }

    EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
    AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
    
    puts("");
    puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");
    
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int KD = 0; KD < AvailableKDs; KD++) {
        strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
        strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
        strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

        RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
        else if (RecentStatus == 1)  { puts("... Status Permintaan: " ANSI_COLOR_YELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
        else if (RecentStatus == 2)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
        else if (RecentStatus == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

        StatusList[KD] = RecentStatus;
        MaxKD++;
        if ((KD + 1) != AvailableKDs) { puts(""); }
    }

    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

    if (MaxKD > 0) { puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET); }
    else {
        puts(ANSI_COLOR_LIGHTORANGE"Data pengajuan bantuan dana dari Kepala Daerah masih kosong!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Mohon maaf, saat ini belum ada Kepala Daerah yang hendak mengajukan bantuan dana kepada Anda...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    }

    puts("");
    puts(ANSI_COLOR_LIGHTMAGENTA"Kepada siapa dari pelbagai data Kepala Daerah di atas untuk Anda berikan bantuan dana?");
    puts(ANSI_COLOR_YELLOW ANSI_STYLE_ITALIC"(kondisi input sesuai penomoran dari masing-masing Kepala Daerah)"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika ingin kembali ke menu sebelumnya, ketik 0 pada input di bawah)"ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", PeekKD);

    if (PeekKD > 0 && PeekKD <= AvailableKDs) {
        ClearScreen();
        
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [4] Pendistribusian Bantuan Dana"ANSI_COLOR_RESET);

        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
        AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));

        puts("");
        puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        for (int KD = 0; KD < AvailableKDs; KD++) {
            strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
            strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
            strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
            KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

            if (KD == (PeekKD - 1)) {
                strcpy(GetKDFullName, KDList.FullName); strcpy(GetKDJobTitle, KDList.JobTitle); strcpy(GetKDHeadRegion, KDList.HeadRegion);
                strcpy(KDFileName, "KD - "); strcat(KDFileName, KDList.FullName); strcat(KDFileName, ".txt");
                EncryptTextFile(KDFileName, "TempKD.txt", -ENCRYPTCODE, false);

                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (KD + 1), KDList.FullName);
                printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);
                printf(ANSI_COLOR_LIGHTWHITE">>> Total Dana Daerah (saat ini): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ReadLine("TempKD.txt", 1)));
                EncryptTextFile("TempKD.txt", KDFileName, ENCRYPTCODE, false); system("del TempKD.txt");

                RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: -"ANSI_COLOR_RESET); }
                else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                else if (RecentStatus == 2)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
            
            } else {
                printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                else if (RecentStatus == 1)  { puts("... Status Permintaan: " ANSI_COLOR_YELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                else if (RecentStatus == 2)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                else if (RecentStatus == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
            }

            StatusList[KD] = RecentStatus;
            if ((KD + 1) != AvailableKDs) { puts(""); }
        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

        puts("");
        if (StatusList[PeekKD - 1] == 0) {
            
            puts(ANSI_COLOR_LIGHTMAGENTA"Sepertinya untuk Kepala Daerah yang bersangkutan saat ini TIDAK dalam masa pengajuan permintaan bantuan dana...");
            puts(ANSI_COLOR_MAGENTA"Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: " ANSI_COLOR_YELLOW"SEDANG DIPROSES!"ANSI_COLOR_RESET);
            
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature04();

        } else if (StatusList[PeekKD - 1] == 2) {
            puts(ANSI_COLOR_LIGHTGREEN"Anda telah MENYETUJUI permintaan bantuan dana dari ajuan Kepala Daerah yang bersengakutan sebelumnya...");
            puts(ANSI_COLOR_GREEN"Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: " ANSI_COLOR_YELLOW"SEDANG DIPROSES!"ANSI_COLOR_RESET);
            
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature04();

        } else if (StatusList[PeekKD - 1] == -1) {
            puts(ANSI_COLOR_LIGHTRED"Anda telah MENOLAK permintaan bantuan dana dari ajuan Kepala Daerah yang bersengakutan sebelumnya...");
            puts(ANSI_COLOR_RED"Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: " ANSI_COLOR_YELLOW"SEDANG DIPROSES!"ANSI_COLOR_RESET);
            
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature04();
        
        } else if (StatusList[PeekKD - 1] == 1) {
            puts(ANSI_COLOR_CYAN"Saat ini Kepala Daerah yang bersangkutan tengah dalam masa pemrosesan dana bantuan dari pihak Anda.");
            puts(ANSI_STYLE_BOLD BRIGHTPINK219"... Apakah Anda yakin untuk menerima pengajuan dari beliau, atau harus menolaknya?");
            puts("... Perhatikan bahwa hal ini akan mengurangi nominal tabungan negara, jadi harap dipastikan terlebih dahulu!");
            
            puts("");
            puts(BRIGHTGREEN156"(sertakan Y atau y untuk menyetujui pengajuan, dan N atau n untuk menolak pengajuan)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                while (true) {
                    ClearScreen();
            
                    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                    puts(BRIGHTGREEN156"\nMenu: [4] Pendistribusian Bantuan Dana"ANSI_COLOR_RESET);

                    EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                    AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
                    
                    OverWriteStringAtLine("Temp_"User_KepalaDaerah, "2", 0, ((10 + 1) * (PeekKD - 1)) + 10);

                    puts("");
                    puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

                    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                    for (int KD = 0; KD < AvailableKDs; KD++) {
                        strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                        strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                        strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                        if (KD == (PeekKD - 1)) {
                            strcpy(GetKDFullName, KDList.FullName); strcpy(GetKDJobTitle, KDList.JobTitle); strcpy(GetKDHeadRegion, KDList.HeadRegion);
                            strcpy(KDFileName, "KD - "); strcat(KDFileName, KDList.FullName); strcat(KDFileName, ".txt");
                            EncryptTextFile(KDFileName, "TempKD.txt", -ENCRYPTCODE, false);

                            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (KD + 1), KDList.FullName);
                            printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);
                            printf(ANSI_COLOR_LIGHTWHITE"... Total Dana Daerah (saat ini): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ReadLine("TempKD.txt", 1)));
                            EncryptTextFile("TempKD.txt", KDFileName, ENCRYPTCODE, false); system("del TempKD.txt");
                            
                            RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                            if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: -"ANSI_COLOR_RESET); }
                            else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                            else if (RecentStatus == 2)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                            else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
                        
                        } else {
                            printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                            printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                            RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                            if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                            else if (RecentStatus == 1)  { puts("... Status Permintaan: " ANSI_COLOR_YELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                            else if (RecentStatus == 2)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                            else if (RecentStatus == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
                        }

                        StatusList[KD] = RecentStatus;
                        if ((KD + 1) != AvailableKDs) { puts(""); }
                    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

                    puts("");
                    puts("Perhatikan arahan di bawah ini, yaitu nominal pemberian harus paling sedikit Rp1,000.00!");
                    AcceptLL(BRIGHTBLUE159"[>= 1000] Berapakah nominal yang Anda kehendaki: ", GivenNomina);
                    
                    if (GivenNomina >= 1000LL) {
                        EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
                        strcpy(WriteString01_A, ReadLine("Temp_"Admin_Kemenkeu, 4));
                        WriteString01_A[strlen(WriteString01_A) - 1] = '\0';
                        snprintf(WriteString02_U, sizeof(WriteString02_U), "%lld", (atoll(WriteString01_A) - GivenNomina));
                        OverWriteStringAtLine("Temp_"Admin_Kemenkeu, WriteString02_U, 0, 4);

                        EncryptTextFile(KDFileName, "TempKD.txt", -ENCRYPTCODE, false);
                        FILE *TempKD = fopen("TempKD.txt", "a");
                        fprintf(TempKD, "[+] Rp%'lld.00: Bantuan Dana dari Kemenkeu\n", (long long int)GivenNomina); fclose(TempKD);
                        fclose(TempKD);
                        snprintf(WriteString03_U, sizeof(WriteString03_U), "%lld", atoll(ReadLine("TempKD.txt", 1)) + GivenNomina);
                        OverWriteStringAtLine("TempKD.txt", WriteString03_U, 0, 1);

                        EncryptTextFile("TempKD.txt", KDFileName, ENCRYPTCODE, false);
                        system("del TempKD.txt");

                        strcpy(WriteString01_A, ReadLine("Temp_"Admin_Kemenkeu, 4));
                        WriteString01_A[strlen(WriteString01_A) - 1] = '\0';

                        AccessAdmin = fopen("Temp_"Admin_Kemenkeu, "a");
                        fprintf(AccessAdmin, "[-] Rp%'lld.00: Bantuan Dana kepada Yth. %s, %s %s\n", (long long int)GivenNomina, GetKDFullName, GetKDJobTitle, GetKDHeadRegion);
                        fclose(AccessAdmin);
                        EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

                        puts("");
                        printf(ANSI_STYLE_BOLD BRIGHTPINK219"... Tabungan Negara saat ini: Rp%'lld.00\n", atoll(WriteString01_A));
                        if (atoll(WriteString01_A) < 1000000000) { puts(ANSI_COLOR_LIGHTRED"... Mohon perhatikan tabungan negara berikut dikarenakan agar tidak berhutang!"); }
                        else                                     { puts(ANSI_COLOR_GREEN"... Saat ini tabungan negara masih aman, tingkatkan terus kinerja Anda!"); }
                        puts(ANSI_COLOR_LIGHTGREEN"Pemberian sumbangan dana tambahan bagi Kepala Daerah yang bersangkutan telah berhasil!"ANSI_COLOR_RESET);
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); AMMFeature04();
                
                    } else {
                        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                        OverWriteStringAtLine("Temp_"User_KepalaDaerah, "1", 0, ((10 + 1) * (PeekKD - 1)) + 10);
                        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                        
                        puts("");
                        puts(ANSI_COLOR_ORANGE"WARNING: Kesalahan input nominal ditemukan! Nominal yang diberikan tidaklah memenuhi syarat...");
                        puts("... Demi keamanan data, mohon dilakukan penyetelan ulang dari awal pilihan!"ANSI_COLOR_RESET);
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause");
                    }
                }
            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                ClearScreen();
        
                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"\nMenu: [4] Pendistribusian Bantuan Dana"ANSI_COLOR_RESET);

                EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
                
                OverWriteStringAtLine("Temp_"User_KepalaDaerah, "-1", 0, ((10 + 1) * (PeekKD - 1)) + 10);

                puts("");
                puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                for (int KD = 0; KD < AvailableKDs; KD++) {
                    strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                    strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                    strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                    KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                    if (KD == (PeekKD - 1)) {
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (KD + 1), KDList.FullName);
                        printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);

                        RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                        if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: -"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 2)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                        else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
                    
                    } else {
                        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                        RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 10));
                        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                        else if (RecentStatus == 1)  { puts("... Status Permintaan: " ANSI_COLOR_YELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 2)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                        else if (RecentStatus == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
                    }

                    StatusList[KD] = RecentStatus;
                    if ((KD + 1) != AvailableKDs) { puts(""); }
                } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

                puts("");
                puts(ANSI_COLOR_LIGHTRED"Anda telah memilih untuk MENOLAK pengajuan permintaan dana bantuan dari Kepala Daerah yang bersangkutan!");
                puts(BRIGHTGREEN156"... Dipersilakan untuk kembali ke menu sebelumnya tanpa modifikasi pengguna..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature04();
            
            } else { CheckInvalidInput = true; AMMFeature04(); }
        }

    } else if (PeekKD == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        AdminMainMenu();

    } else { CheckInvalidInput = true; AMMFeature04(); }
}

void AMMFeature05(void) {
    FILE *AccessCart, *AccessKD;
    Keranjang CartInfo = { 0 };

    char CurrentCartFile[BUFSIZE07];
    char ConfirmRequest, UpdateStatus, CurrentFileKD[BUFSIZE07] = { 0 }, WriteFinalSavings[BUFSIZE07] = { 0 }, FinalWrittenReqs[BUFSIZE07] = { 0 };
    char DisplayKDFullName[BUFSIZE07] = { 0 }, *DisplayKDJobTitle = "", *DisplayKDHeadRegion = "";
    char DisplaySIFullName[BUFSIZE07] = { 0 }, *DisplaySIIndustryName = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock = "", *DisplayProductPrice = "";
    int AllLinkedRequests[BUFSIZE10] = { 0 }, AllRequestsID[BUFSIZE10] = { 0 };
    int OCManaging = 0, SetNewReqs = 0;
    int AdminStatus = 0, AvailableReqs = 0, MaxReq = 0, PeekReq = 0, GetReq = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature05();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

    EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
    AdminStatus = atoi(ReadLine("Temp_"Admin_Kemenkeu, 5));
    EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

    puts("");
    printf(ANSI_COLOR_MAGENTA"Saat ini STATUS penerimaan kerja sama/distribusi terbuka Anda: ");
    if      (AdminStatus == 0) { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
    else if (AdminStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }
    puts(ANSI_COLOR_YELLOW"... Pengaturan di atas dapat Anda atur dari pilihan kedua menu berikut!"ANSI_COLOR_RESET);

    puts("");
    puts(BRIGHTBLUE159"[1] BUKA/TUTUP jasa pengajuan kerja sama dengan Kepala Daerah");
    puts(BRIGHTBLUE159"[2] KELOLA pelbagai pengajuan kerja sama dari masing-masing Kepala Daerah"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED"[0] Kembali..."ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", OCManaging);
    
    if (OCManaging == 1) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

        puts("");
        printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
        if (AdminStatus == 0) {
            puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);
            
            puts("");
            puts(ANSI_COLOR_CYAN"Apakah Anda menghendaki untuk MEMBUKA peluang pengajuan kerja sama dengan Kepala Daerah?");
            puts(ANSI_STYLE_ITALIC"(cukup sertakan Y atau y jika setuju, dan N atau n untuk tetap menutupnya)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                ClearScreen();

                EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
                OverWriteStringAtLine("Temp_"Admin_Kemenkeu, "1", 0, 5);
                AdminStatus = atoi(ReadLine("Temp_"Admin_Kemenkeu, 5));
                EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
                if (AdminStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
                else if (AdminStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

                puts("");
                puts(ANSI_COLOR_LIGHTGREEN"Anda telah MEMBUKA sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();

            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                puts("");
                puts(ANSI_COLOR_LIGHTRED"Anda tetap MENUTUP sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();
            }

        } else if (AdminStatus == 1) {
            puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET);
        
            puts("");
            puts(ANSI_COLOR_CYAN"Apakah Anda menghendaki untuk MENUTUP peluang pengajuan kerja sama dengan Kepala Daerah?");
            puts(ANSI_STYLE_ITALIC"(cukup sertakan Y atau y jika setuju, dan N atau n untuk tetap menutupnya)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                ClearScreen();

                EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
                OverWriteStringAtLine("Temp_"Admin_Kemenkeu, "0", 0, 5);
                AdminStatus = atoi(ReadLine("Temp_"Admin_Kemenkeu, 5));
                EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
                if (AdminStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
                else if (AdminStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

                puts("");
                puts(ANSI_COLOR_LIGHTRED"Anda telah MENUTUP sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();

            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                puts("");
                puts(ANSI_COLOR_LIGHTGREEN"Anda tetap MEMBUKA sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();
            }
        }
    
    } else if (OCManaging == 2 && AdminStatus == 1) {
        while (true) {
            MaxReq = 0;

            ClearScreen();
            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

            EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
            AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

            puts("");
            puts("Berikut adalah data pengajuan distribusi barang produksi dari Kepala Daerah kepada Anda:");

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            for (int REQ = 0; REQ < AvailableReqs; REQ++) {
                strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 3));
                strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 4));
                strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
                CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 6));

                AllRequestsID[REQ] = REQ;
                if (CartInfo.Status == 2) {
                    strcpy(DisplayKDFullName, CartInfo.Requester);
                    strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
                    strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
                    strcpy(DisplaySIFullName, CartInfo.Accepter);
                    strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);
                    MaxReq++; AllLinkedRequests[REQ] = MaxReq;

                    printf("[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, MaxReq, DisplayKDFullName);
                    printf("... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, DisplayKDJobTitle, DisplayKDHeadRegion);
                    puts("... Status Pengajuan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET);

                    strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
                    DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                    strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                    strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                    
                    puts("");
                    printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                    printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

                    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                
                } else { AllLinkedRequests[REQ] = MaxReq; }
            }

            EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

            if (MaxReq == 0) {
                puts(ANSI_COLOR_LIGHTORANGE"Data pengajuan distribusi produk dari Kepala Daerah tengah KOSONG!");
                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                puts("");
                puts(BRIGHTGREEN154"PERHATIAN: Saat ini belum ada Kepala Daerah yang hendak mengajukan distribusi barang kepada Kemenkeu!");
                puts("...        Silakan untuk ditunggu dan diperhatikan menu ini secara berkala..."ANSI_COLOR_RESET);

                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();
            }

            puts("");
            printf(ANSI_COLOR_MAGENTA"Saat ini, tersedia %d PESANAN dari Kepala Daerah yang siap untuk didistribusikan kepada Anda. " ANSI_COLOR_LIGHTGREEN"TERIMA AJUAN sekarang?\n", MaxReq);
            puts(ANSI_COLOR_GREEN"... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini..."ANSI_COLOR_RESET);
            puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
            AcceptInputOption("> Pilihan Anda: ", PeekReq);

            if (PeekReq > 0 && PeekReq <= MaxReq) {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);
                
                for (size_t i = 0; i < sizeof(AllLinkedRequests)/sizeof(AllLinkedRequests[0]); i++) {
                    if (AllLinkedRequests[i] != PeekReq) { GetReq++; }
                    else { break; }
                    // if (GetReq != (PeekReq - 1)) { if (AllLinkedRequests[i] == 1) { GetReq++; } else { continue; } }
                    // else { break; };
                }

                EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                
                strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 3));
                strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 4));
                strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 6));

                strcpy(DisplayKDFullName, CartInfo.Requester);
                strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
                strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
                strcpy(DisplaySIFullName, CartInfo.Accepter);
                strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

                puts("");
                puts("Berikut adalah data keranjang pesanan Kepala Daerah yang siap didistribusikan kepada Anda:");

                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                if (CartInfo.Status == 2) {
                    printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, GetReq, DisplayKDFullName);
                    printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, DisplayKDJobTitle, DisplayKDHeadRegion);
                    puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET);

                    strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                    DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                    strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                    strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                    
                    puts("");
                    printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                    printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);            
                EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
                
                puts("");
                puts(BRIGHTBLUE159"Berikut adalah besar pengeluaran yang Anda keluarkan apabila pihak Anda menerima ajuan distribusi Kepala Daerah yang bersangkutan:");
                printf(BRIGHTGREEN156"Harga Total Pesanan: Rp%'lld.00 " BRIGHTPINK219"(+%0.2f%%) " BRIGHTGREEN156">> " BRIGHTBLUE159"Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine("Temp_"Admin_Kemenkeu, 3)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f))));
                puts(BRIGHTPINK219"... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Kemenkeu!"ANSI_COLOR_RESET);
                puts(BRIGHTPINK219"...          Pengeluaran tersebut akan menjadi pemasukkan bagi Kepala Daerah yang bersangkutan..."ANSI_COLOR_RESET);

                EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

                puts("");
                puts(ANSI_COLOR_MAGENTA"Setelah melihat data di atas, Anda berhak untuk MENGELOLA permintaan distribusi ini dari Kepala Daerah tersebut. " ANSI_COLOR_LIGHTYELLOW"Kelola SEKARANG?");
                puts(ANSI_COLOR_YELLOW"... Apabila Anda MENOLAK pengajuan dari yang bersangkutan, Anda masih dapat MENERIMA-nya kembali di lain waktu..."ANSI_COLOR_RESET);
                
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(ketik Y atau y jika hendak MENERIMA, dan N atau n apabila MENOLAK)");
                puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika ingin kembali ke menu sebelumnya, ketik Q atau q)"ANSI_COLOR_RESET);
                AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

                if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
                    ClearScreen();

                    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                    puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                    EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);

                    puts("");
                    puts("Berikut adalah data keranjang pesanan Kepala Daerah yang TELAH didistribusikan kepada Anda:");

                    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                    if (CartInfo.Status == 2 && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, GetReq, DisplayKDFullName);
                        printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, DisplayKDJobTitle, DisplayKDHeadRegion);
                        puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET);

                        strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                        
                        puts("");
                        printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                        printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                    
                    EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
                    EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
                    
                    strcpy(Belanja.Requester, CartInfo.Requester);
                    strcpy(Belanja.Accepter, CartInfo.Accepter);
                    snprintf(Belanja.ProductInDemand, sizeof(Belanja.ProductInDemand) + 13, "%s, %s, %lld", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)));
                    Belanja.Status = 0;
                    Belanja.Requester[strlen(Belanja.Requester) - 1] = '\0'; Belanja.Accepter[strlen(Belanja.Accepter) - 1] = '\0';
                    WritePrivateKeranjang(true, 0, false);

                    snprintf(WriteFinalSavings, sizeof(WriteFinalSavings), "%lld", atoll(ReadLine("Temp_"Admin_Kemenkeu, 4)) - (atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f))));
                    OverWriteStringAtLine("Temp_"Admin_Kemenkeu, WriteFinalSavings, 0, 4);

                    EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                    AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

                    char WriteNewSavings[BUFSIZE07] = { 0 };
                    snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 12, "KD - %s.txt", DisplayKDFullName);
                    EncryptTextFile(CurrentFileKD, "TempKD.txt", -ENCRYPTCODE, false);
                    AccessKD = fopen("TempKD.txt", "a");
                    fprintf(AccessKD, "[+] Rp%'lld.00: Distribusi produk (%s: %s) item, dari Yth. %s, Direktur %s, kepada Kemenkeu\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), DisplayProductName, DisplayProductStock, DisplaySIFullName, DisplaySIIndustryName);
                    fclose(AccessKD);
                    snprintf(WriteNewSavings, sizeof(WriteNewSavings), "%lld", atoll(ReadLine("TempKD.txt", 1)) + (atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f))));
                    OverWriteStringAtLine("TempKD.txt", WriteNewSavings, 0, 1);
                    EncryptTextFile("TempKD.txt", CurrentFileKD, ENCRYPTCODE, false); system("del TempKD.txt");

                    strcpy(CurrentCartFile, "New_"UserCartStore_Keranjang);
                    AccessCart = fopen(CurrentCartFile, "w");
                    
                    fprintf(AccessCart, "0\n");
                    for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
                        strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 3));
                        strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 4));
                        strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 5));
                        CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 6));
                        CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
                        
                        if (CartInfo.Status == 2 && ReqID == AllRequestsID[GetReq] && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                            continue;
                        } else {
                            SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                            fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
                        }
                    } fclose(AccessCart);

                    snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
                    OverWriteStringAtLine("New_"UserCartStore_Keranjang, FinalWrittenReqs, 0, 1);
                    EncryptTextFile("New_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
                    system("del Temp_"UserCartStore_Keranjang);

                    FILE *AccessAdmin = fopen("Temp_"Admin_Kemenkeu, "a");
                    fprintf(AccessAdmin, "[-] Rp%'lld.00: Pembelian produk pada Kepala Daerah (%s: %s) item, dari Yth. %s, %s %s\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), DisplayProductName, DisplayProductStock, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);
                    fclose(AccessAdmin);
                    
                    puts("");
                    puts(BRIGHTBLUE159"Berikut adalah besar pengeluaran yang Anda keluarkan dari persetujuan distribusinya:");
                    printf(BRIGHTGREEN156"Besar/Nilai Pengeluaran Anda: Rp%'lld.00 " BRIGHTBLUE159"<< (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)));
                    puts(BRIGHTPINK219"... CATATAN: Besar pengeluaran di atas akan menimbulkan efek pada Tabungan Negara Anda, jadi mohon untuk dipantau secara berkala!");
                    puts(BRIGHTPINK219"...          Pesanan distribusi yang sudah Anda konfirmasi TIDAK DAPAT Anda batalkan kembali..."ANSI_COLOR_RESET);

                    EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

                    puts("");
                    puts(ANSI_COLOR_LIGHTGREEN"Status Pengajuan: PENGAJUAN DITERIMA (TIDAK DAPAT DIBATALKAN, PERMANEN)");
                    puts(ANSI_COLOR_GREEN":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah dengan Sektor Industri yang bersangkutan...");
                    puts(ANSI_COLOR_GREEN":: Kini Anda siap untuk mendistribusikan produk pesanan tersebut ke skala INTERNASIONAL!"ANSI_COLOR_RESET);

                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause"); AMMFeature05();
                
                } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
                    ClearScreen();

                    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
                    puts(BRIGHTGREEN156"\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                    EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);

                    puts("");
                    puts("Berikut adalah data keranjang pesanan Kepala Daerah yang MENUNGGU untuk didistribusikan kepada Anda:");

                    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                    if (CartInfo.Status == 2 && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, GetReq, DisplayKDFullName);
                        printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, DisplayKDJobTitle, DisplayKDHeadRegion);
                        puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET);

                        strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                        
                        puts("");
                        printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                        printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                    
                    EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"Status Pengajuan: PENGAJUAN DITOLAK (UNTUK SEKARANG, TIDAK PERMANEN)");
                    puts(ANSI_COLOR_RED":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                    puts(ANSI_COLOR_RED":: Namun jangan khawatir, karena Anda masih dapat MENERIMA pengajuannya kembali di lain waktu!"ANSI_COLOR_RESET);

                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause"); AMMFeature05();
                
                } else if (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                } else {
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                }
            
            } else if (PeekReq == 0) {
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); AMMFeature05();
            } else { CheckInvalidInput = true; AMMFeature05(); }
        }
    
    } else if (OCManaging == 2 && AdminStatus == 0) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

        puts("");
        printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
        if (AdminStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
        else if (AdminStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

        puts("");
        puts(ANSI_COLOR_LIGHTMAGENTA"Sekedar informasi, bahwa Anda tidak dapat mengelola pengajuan-pengajuan yang disampaikan oleh pelbagai");
        puts("pihak Kepala Daerah jika status penerimaan pengajuan Anda saat ini sedang TIDAK AKTIF!");
        puts(ANSI_COLOR_GREEN"... Silakan untuk DIBUKA terlebih dahulu akses pengajuannya agar Anda dapat mengelola lebih lenjut..."ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AMMFeature05();

    } else if (OCManaging == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    } else { CheckInvalidInput = true; AMMFeature05(); }
}

void AMMFeature06(void) {
    FILE *AccessCart;
    Keranjang CartInfo = { 0 };

    char CurrentCartFile[BUFSIZE07] = { 0 };
    char ConfirmRequest, WriteFinalSavings[BUFSIZE07] = { 0 }, FinalWrittenReqs[BUFSIZE07] = { 0 };
    char DisplayKDFullName[BUFSIZE07] = { 0 }, *DisplayKDJobTitle = "", *DisplayKDHeadRegion = "";
    char DisplaySIFullName[BUFSIZE07] = { 0 }, *DisplaySIIndustryName = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock = "", *DisplayProductPrice = "";
    int SetNewReqs = 0;
    int AvailableReqs = 0, MaxReq = 0, PeekReq = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AMMFeature06();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"\nMenu: [6] Distribusi Perdagangan Internasional"ANSI_COLOR_RESET);

    EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);
    AvailableReqs = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, 1));

    puts("");
    puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int REQ = 0; REQ < AvailableReqs; REQ++) {
        strcpy(CartInfo.Requester, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * REQ) + 3));
        strcpy(CartInfo.Accepter, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * REQ) + 4));
        strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * REQ) + 5));
        CartInfo.Status = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * REQ) + 6));

        MaxReq++;
        strcpy(DisplayKDFullName, CartInfo.Requester);
        strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
        strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
        strcpy(DisplaySIFullName, CartInfo.Accepter);
        strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

        if      (CartInfo.Status == 0) puts(ANSI_COLOR_YELLOW"STATUS REVIEW: "ANSI_COLOR_LIGHTYELLOW"BELUM DILIHAT"ANSI_COLOR_RESET);
        else if (CartInfo.Status == 1) puts(ANSI_COLOR_GREEN"STATUS REVIEW: "ANSI_COLOR_LIGHTGREEN"TELAH DILIHAT"ANSI_COLOR_RESET);

        puts("");
        printf(BRIGHTBLUE159"[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", MaxReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

        strcpy(DisplayProductName, CartInfo.ProductInDemand);
        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
        
        printf(BRIGHTPURPLE218"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
        printf(BRIGHTPURPLE218"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);        
    }

    EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);

    if (MaxReq == 0) {
        puts(ANSI_COLOR_LIGHTORANGE"Daftar keranjang belanja distribusi produk Anda tengah KOSONG!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(BRIGHTGREEN154"PERHATIAN: Saat ini Anda belumm menerima daftar keranjang dari Kepala Daerah yang mengajukannya!");
        puts("...        Silakan untuk ditunggu dan diperhatikan menu ini secara berkala..."ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    }

    puts("");
    printf(ANSI_COLOR_MAGENTA"Saat ini, tersedia %d produk di keranjang Anda. " ANSI_COLOR_LIGHTGREEN"DISTRIBUSIKAN SKALA INTERNASIONAL sekarang?\n", MaxReq);
    puts(ANSI_COLOR_GREEN"... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini..."ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", PeekReq);

    if (PeekReq > 0 && PeekReq <= MaxReq) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"\nMenu: [6] Distribusi Perdagangan Internasional"ANSI_COLOR_RESET);

        EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);
        
        strcpy(CartInfo.Requester, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 3));
        strcpy(CartInfo.Accepter, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 4));
        strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 5));
        CartInfo.Status = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 6));

        strcpy(DisplayKDFullName, CartInfo.Requester);
        strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
        strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
        strcpy(DisplaySIFullName, CartInfo.Accepter);
        strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

        puts("");
        puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        if      (CartInfo.Status == 0) puts(ANSI_COLOR_YELLOW"STATUS REVIEW: "ANSI_COLOR_LIGHTYELLOW"BELUM DILIHAT"ANSI_COLOR_RESET);
        else if (CartInfo.Status == 1) puts(ANSI_COLOR_GREEN"STATUS REVIEW: "ANSI_COLOR_LIGHTGREEN"TELAH DILIHAT"ANSI_COLOR_RESET);
        
        puts("");
        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", PeekReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

        strcpy(DisplayProductName, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 5));
        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
        
        printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
        printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);            
        EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
        
        puts("");
        puts(BRIGHTBLUE159"Berikut adalah besar pendapatan yang Anda keluarkan apabila pihak Anda mendistribusikan produk yang bersangkutan:");
        printf(BRIGHTGREEN156"Harga Total Pesanan: Rp%'lld.00 " BRIGHTPINK219"(+%0.2f%%) " BRIGHTGREEN156">> " BRIGHTBLUE159"Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine("Temp_"Admin_Kemenkeu, 3)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f))));
        puts(BRIGHTPINK219"... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Anda sendiri!"ANSI_COLOR_RESET);

        EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Setelah melihat data di atas, Anda berhak untuk MENGELOLA distribusi produk tersebut. " ANSI_COLOR_LIGHTYELLOW"Kelola SEKARANG?");
        puts(ANSI_COLOR_YELLOW"... Apabila Anda belum ingin mendistribusikanya dalam skala internasional, Anda dapat melakukannya di lain waktu..."ANSI_COLOR_RESET);
        
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(ketik Y atau y jika hendak MENERIMA, dan N atau n apabila MENOLAK)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika ingin kembali ke menu sebelumnya, ketik Q atau q)"ANSI_COLOR_RESET);
        AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

        if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"\nMenu: [6] Distribusi Perdagangan Internasional"ANSI_COLOR_RESET);

            EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);

            puts("");
            puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            if      (CartInfo.Status == 0) puts(ANSI_COLOR_YELLOW"STATUS REVIEW: "ANSI_COLOR_LIGHTYELLOW"BELUM DILIHAT"ANSI_COLOR_RESET);
            else if (CartInfo.Status == 1) puts(ANSI_COLOR_GREEN"STATUS REVIEW: "ANSI_COLOR_LIGHTGREEN"TELAH DILIHAT"ANSI_COLOR_RESET);
            
            puts("");
            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", PeekReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

            strcpy(DisplayProductName, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
            printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

            AvailableReqs = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, 1));
            strcpy(CurrentCartFile, "New_"AdminCartStore_Keranjang);
            AccessCart = fopen(CurrentCartFile, "w");

            fprintf(AccessCart, "0\n");
            for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
                strcpy(CartInfo.Requester, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ReqID) + 3));
                strcpy(CartInfo.Accepter, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ReqID) + 4));
                strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ReqID) + 5));
                CartInfo.Status = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ReqID) + 6));
                CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
                
                if (ReqID == (PeekReq - 1)) {
                    continue;
                } else {
                    SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                    fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
                }
            } fclose(AccessCart);

            snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
            OverWriteStringAtLine("New_"AdminCartStore_Keranjang, FinalWrittenReqs, 0, 1);
            EncryptTextFile("New_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);
            system("del Temp_"AdminCartStore_Keranjang);

            EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
            
            snprintf(WriteFinalSavings, sizeof(WriteFinalSavings), "%lld", atoll(ReadLine("Temp_"Admin_Kemenkeu, 4)) + atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)));
            OverWriteStringAtLine("Temp_"Admin_Kemenkeu, WriteFinalSavings, 0, 4);

            FILE *AccessAdmin = fopen("Temp_"Admin_Kemenkeu, "a");
            fprintf(AccessAdmin, "[+] Rp%'lld.00: Distribusi produk (%s: %s) item, dari Yth. %s, Direktur %s, skala Internasional\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), DisplayProductName, DisplayProductStock, DisplaySIFullName, DisplaySIIndustryName);
            fclose(AccessAdmin);
            
            puts("");
            puts(BRIGHTBLUE159"Berikut adalah besar pendapatan yang Anda terima dari persetujuan distribusinya:");
            printf(BRIGHTGREEN156"Besar/Nilai Pendapatan Anda: Rp%'lld.00 " BRIGHTBLUE159"<< (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)));
            puts(BRIGHTPINK219"... CATATAN: Besar pendapatan di atas akan menimbulkan efek pada Tabungan Negara Anda, jadi mohon untuk dipantau secara berkala!");
            puts(BRIGHTPINK219"...          Pesanan distribusi yang sudah Anda konfirmasi TIDAK DAPAT Anda batalkan kembali..."ANSI_COLOR_RESET);

            EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

            puts("");
            puts(ANSI_COLOR_LIGHTGREEN"Status Distribusi: DISTRIBUSI SUKSES (TIDAK DAPAT DIBATALKAN, PERMANEN)");
            puts(ANSI_COLOR_GREEN":: Selamat, Anda telah mendistribusikan barang produksi yang bersangkutan ke skala internasional..."ANSI_COLOR_RESET);

            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature06();
        
        } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTGREEN156 ANSI_STYLE_BOLD"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"\nMenu: [6] Distribusi Perdagangan Internasional"ANSI_COLOR_RESET);

            EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);

            puts("");
            puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            if      (CartInfo.Status == 0) puts(ANSI_COLOR_YELLOW"STATUS REVIEW: "ANSI_COLOR_LIGHTYELLOW"BELUM DILIHAT"ANSI_COLOR_RESET);
            else if (CartInfo.Status == 1) puts(ANSI_COLOR_GREEN"STATUS REVIEW: "ANSI_COLOR_LIGHTGREEN"TELAH DILIHAT"ANSI_COLOR_RESET);
            
            puts("");
            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", PeekReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

            strcpy(DisplayProductName, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * (PeekReq - 1)) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            printf(ANSI_COLOR_LIGHTWHITE"Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
            printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            
            EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);

            puts("");
            puts(ANSI_COLOR_LIGHTRED"Status Distribusi: DISTRIBUSI DITUNDA (UNTUK SEKARANG, TIDAK PERMANEN)");
            puts(ANSI_COLOR_RED":: Sepertinya saat ini Anda masih belum ingin mendistribusikan barang produksi yang bersangkutan...");
            puts(ANSI_COLOR_RED":: Namun jangan khawatir, karena Anda masih dapat MENDISTRIBUSIKANNYA kembali di lain waktu!"ANSI_COLOR_RESET);

            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature06();
        
        } else if (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); AMMFeature06();
        } else { CheckInvalidInput = true; AMMFeature06(); }
    
    } else if (PeekReq == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); AdminMainMenu();
    } else { CheckInvalidInput = true; AMMFeature06(); }
}

void UserMainMenu(void) {
    int UMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        AdminMainMenu();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
    printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);

    puts("");
    puts(BRIGHTBLUE159 ANSI_STYLE_ITALIC "~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"[1] Alur Perekonomian Dana Daerah: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Menampilkan data pemasukkan serta pengeluaran dana di daerah tersebut."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[2] Pengajuan Dana Bantuan dari Pemerintah Pusat: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengajukan permintaan bantuan dana tambahan kepada pihak Kemenkeu."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[3] Distribusi Pemerintah Pusat: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengajukan proses pendistribusian produksi industri terhadap pihak Kemenkeu."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[4] Pengaturan Kerja Sama dengan Sektor Industri: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengajukan proses kerja sama dengan pihak sektor industri (Client)"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED ANSI_STYLE_BOLD"[0] Keluar..."ANSI_COLOR_RESET);

    puts("");
    puts("Anda dipersilakan untuk memilih dari EMPAT (4) opsi di atas... .");
    AcceptInputOption("> Pilihan Anda: ", UMMOption);

    switch (UMMOption) {
        case 1:  { UMMFeature01(); } break;
        case 2:  { UMMFeature02(); } break;
        case 3:  { UMMFeature03(); } break;
        case 4:  { UMMFeature04(); } break;
        case 0:  { 
            KDLoggedIn = 0; KDFullName[0] = 0; KDJobTitle[0] = 0; KDHeadRegion[0] = 0;
            HomeMenu();
        } break;
        default: { CheckInvalidInput = true; UserMainMenu(); } break;
    }
}

void UMMFeature01(void) {
    char CurrentFileKD[BUFSIZE07] = { 0 }, KDSSPositive[BUFSIZE07] = { 0 }, KDSSNegative[BUFSIZE07] = { 0 };
    char TotalSavings[BUFSIZE07] = { 0 };

    ClearScreen();
    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
    printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
    puts(BRIGHTBLUE158"\nMenu: [1] Alur Perekonomian Dana Daerah"ANSI_COLOR_RESET);

    snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 12, "KD - %s.txt", KDFullName);

    EncryptTextFile(CurrentFileKD, "TempKD.txt", -ENCRYPTCODE, false);
    strcpy(TotalSavings, ReadLine("TempKD.txt", 1));
    TotalSavings[strlen(TotalSavings) - 1] = '\0';
    snprintf(KDSSPositive, sizeof(KDSSPositive) + 9, "%s > [+]", CurrentFileKD);
    snprintf(KDSSNegative, sizeof(KDSSNegative) + 9, "%s > [-]", CurrentFileKD);
    EncryptTextFile("TempKD.txt", CurrentFileKD, ENCRYPTCODE, true);

    puts("");
    puts("Berikut adalah data akumulasi perekonomian dana daerah dari yang bersangkutan:");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    printf(BRIGHTGREEN156"Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
    puts(BRIGHTBLUE159"Pemasukkan (Incomes): ");
    DecryptTextFile(CurrentFileKD, false, ENCRYPTCODE, KDSSPositive); puts("");
    puts(BRIGHTMAGENTA211"Pengeluaran (Expenses): ");
    DecryptTextFile(CurrentFileKD, false, ENCRYPTCODE, KDSSNegative);
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    puts("");
    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
    system("pause");
    UserMainMenu();
}

void UMMFeature02(void) {
    char OpenRequest = 0;
    int RecentStatus = 0;
    
    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        UMMFeature02();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
    printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
    puts(BRIGHTBLUE158"\nMenu: [2] Pengajuan Dana Bantuan dari Pemerintah Pusat"ANSI_COLOR_RESET);

    EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
    RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KDLoggedIn) + 10));
    
    puts("");
    puts("Berikut adalah status permintaan bantuan dana Anda saat ini:");
    if      (RecentStatus == 0)  { puts(":: Status Permintaan: -"); }
    else if (RecentStatus == 1)  { puts(ANSI_COLOR_YELLOW":: Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"); }
    else if (RecentStatus == 2)  { puts(ANSI_COLOR_GREEN":: Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"); puts(ANSI_COLOR_GREEN":: Anda dapat melihat nominal pemberian dari Kemenkeu pada menu Alur Perekonomian Daerah Anda... "); }
    else if (RecentStatus == -1) { puts(ANSI_COLOR_RED":: Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

    puts("");
    if (RecentStatus == 0 || RecentStatus == 2 || RecentStatus == -1) {
        puts(ANSI_COLOR_LIGHTMAGENTA"Ajukan permintaan bantuan dana kepada pihak Kemenkeu?");
        puts(ANSI_COLOR_PINK ANSI_STYLE_ITALIC"(ketik Y atau y jika hendak mengajukan, selain itu ketik N atau n)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(ketik Q atau q untuk keluar...)"ANSI_COLOR_RESET);
        AcceptCharInput("> Pilihan Anda: ", OpenRequest);
        
        if (OpenRequest == 'Y' || OpenRequest == 'y') {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
            printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
            puts(BRIGHTBLUE158"\nMenu: [2] Pengajuan Dana Bantuan dari Pemerintah Pusat"ANSI_COLOR_RESET);

            EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
            OverWriteStringAtLine("Temp_"User_KepalaDaerah, "1", 0, ((10 + 1) * KDLoggedIn) + 10);
            RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KDLoggedIn) + 10));
            EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
            
            puts("");
            puts("Berikut adalah status permintaan bantuan dana Anda saat ini:");
            if      (RecentStatus == 0)  { puts(":: Status Permintaan: -"); }
            else if (RecentStatus == 1)  { puts(ANSI_COLOR_YELLOW":: Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"); }
            else if (RecentStatus == 2)  { puts(ANSI_COLOR_GREEN":: Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"); puts(ANSI_COLOR_GREEN":: Anda dapat melihat nominal pemberian dari Kemenkeu pada menu Alur Perekonomian Daerah Anda... "); }
            else if (RecentStatus == -1) { puts(ANSI_COLOR_RED":: Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
            
            puts("");
            puts(ANSI_COLOR_GREEN"Pengajuan permintaan bantuan dana telah berhasil!"ANSI_COLOR_RESET);
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UMMFeature02();
            
        } else if (OpenRequest == 'N' || OpenRequest == 'n') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UMMFeature02();
        } else if (OpenRequest == 'Q' || OpenRequest == 'q') {            
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UserMainMenu();
        } else { CheckInvalidInput = true; UMMFeature02(); }

    } else if (RecentStatus == 1) {
        puts(ANSI_COLOR_LIGHTMAGENTA"Saat ini permintaan bantuan dana Anda sedang diproses. Batalkan pengajuan?");
        puts(ANSI_COLOR_PINK ANSI_STYLE_ITALIC"(ketik Y atau y jika hendak membatalkan, selain itu ketik N atau n)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(ketik Q atau q untuk keluar...)"ANSI_COLOR_RESET);
        AcceptCharInput("> Pilihan Anda: ", OpenRequest);

        if (OpenRequest == 'Y' || OpenRequest == 'y') {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
            printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
            puts(BRIGHTBLUE158"\nMenu: [2] Pengajuan Dana Bantuan dari Pemerintah Pusat"ANSI_COLOR_RESET);

            EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
            OverWriteStringAtLine("Temp_"User_KepalaDaerah, "0", 0, ((10 + 1) * KDLoggedIn) + 10);
            RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KDLoggedIn) + 10));
            EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
            
            puts("");
            puts("Berikut adalah status permintaan bantuan dana Anda saat ini:");
            if      (RecentStatus == 0)  { puts(":: Status Permintaan: -"); }
            else if (RecentStatus == 1)  { puts(ANSI_COLOR_YELLOW":: Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"); }
            else if (RecentStatus == 2)  { puts(ANSI_COLOR_GREEN":: Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"); puts(ANSI_COLOR_GREEN":: Anda dapat melihat nominal pemberian dari Kemenkeu pada menu Alur Perekonomian Daerah Anda... "); }
            else if (RecentStatus == -1) { puts(ANSI_COLOR_RED":: Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }
            
            puts("");
            puts(ANSI_COLOR_GREEN"Pembatalan pengajuan bantuan dana telah berhasil!"ANSI_COLOR_RESET);
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UMMFeature02();

        } else if (OpenRequest == 'N' || OpenRequest == 'n') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UMMFeature02();
        }  else if (OpenRequest == 'Q' || OpenRequest == 'q') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
            UserMainMenu();
        } else { CheckInvalidInput = true; UMMFeature02(); }
    }
}

void UMMFeature03(void) {
    Keranjang CartInfo = { 0 };
    char ConfirmRequest;
    char DisplaySIFullName[BUFSIZE07] = { 0 }, *DisplaySIIndustryName = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock = "", *DisplayProductPrice = "";
    int AllLinkedRequests[BUFSIZE10] = { 0 }, AllRequestsID[BUFSIZE10] = { 0 };
    int AdminStatus = 0;
    int AvailableConfirms = 0, AvailableReqs = 0, MaxConfirms = 0, MaxReq = 0, PeekReq = 0, GetReq = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        UMMFeature03();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
    printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
    puts(BRIGHTBLUE158"\nMenu: [3] Distribusi Pemerintah Pusat"ANSI_COLOR_RESET);

    EncryptTextFile(AdminCartStore_Keranjang, "Temp_"AdminCartStore_Keranjang, -ENCRYPTCODE, true);
    AvailableConfirms = atoi(ReadLine("Temp_"AdminCartStore_Keranjang, 1));

    for (int ACC = 0; ACC < AvailableConfirms; ACC++) {
        if (strstr(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 3), KDFullName) != NULL && strstr(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 3), KDJobTitle) != NULL && strstr(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 3), KDHeadRegion)) {
            if (atoi(ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 6)) == 0) {
                MaxConfirms++;
                OverWriteStringAtLine("Temp_"AdminCartStore_Keranjang, "1", 0, ((4 + 1) * ACC) + 6);
                
                puts(BRIGHTBLUE159"===================================================================================================="ANSI_COLOR_RESET);
                puts(ANSI_COLOR_GREEN"Status Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA");
                puts(ANSI_COLOR_GREEN":: Selamat, pengajuan distribusi produk Anda telah diterima oleh Kemenkeu!");
                puts(ANSI_COLOR_YELLOW":: Berikut informasi produk yang bersangkutan... Semangat berbisnis!"ANSI_COLOR_RESET);

                strcpy(DisplaySIFullName, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 4));
                DisplaySIFullName[strlen(DisplaySIFullName) - 1] = '\0';
                strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);
                strcpy(DisplayProductName, ReadLine("Temp_"AdminCartStore_Keranjang, ((4 + 1) * ACC) + 5));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);

                puts("");
                printf(BRIGHTPURPLE218"[%03d] Sektor Industri :: Yth. %s, Direktur %s\n", MaxConfirms, DisplaySIFullName, DisplaySIIndustryName);
                printf("... Nama dan Stok Produk: %s, %s item\n", DisplayProductName, DisplayProductStock);
                printf(BRIGHTGREEN156"... Pendapatan Total (+Bonus Pajak): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(DisplayProductPrice));
                
            }
        }
    } if (MaxConfirms > 0) {
        EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);
        puts(BRIGHTBLUE159"===================================================================================================="ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UMMFeature03();
    }

    EncryptTextFile("Temp_"AdminCartStore_Keranjang, AdminCartStore_Keranjang, ENCRYPTCODE, true);
    EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
    AdminStatus = atoi(ReadLine("Temp_"Admin_Kemenkeu, 5));
    EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

    puts("");
    puts(BRIGHTPINK219"===================================================================================================="ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka dari Kemenkeu: ");
    if      (AdminStatus == 0) { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
    else if (AdminStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }
    puts(BRIGHTPINK219"===================================================================================================="ANSI_COLOR_RESET);

    if (AdminStatus == 0) {
        puts("");
        puts(ANSI_COLOR_LIGHTRED"Mohon maaf, saat ini pihak Kemenkeu tengah MENONAKTIFKAN masa pengajuan untuk sementara waktu!");
        puts(ANSI_COLOR_RED"... Harap untuk menunggu lebih lanjut mengenai kabar masa pengajuan menjadi AKTIF ke depannya..."ANSI_COLOR_RESET);
        
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();
    }

    EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
    AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

    puts("");
    puts("Berikut adalah data keranjang pelbagai pesanan Anda yang SIAP didistribusikan kepada Kemenkeu:");

    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int REQ = 0; REQ < AvailableReqs; REQ++) {
        strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 3));
        strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 4));
        strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
        CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 6));

        AllRequestsID[REQ] = REQ;
        if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            MaxReq++; AllLinkedRequests[REQ] = MaxReq;

            printf("[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (MaxReq), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: " ANSI_COLOR_LIGHTGREEN"SIAP DIDISTRIBUSIKAN"ANSI_COLOR_RESET);

            strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        
        } else if (CartInfo.Status == 2 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            MaxReq++; AllLinkedRequests[REQ] = MaxReq;

            printf("[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (MaxReq), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET);

            strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        
        } else { AllLinkedRequests[REQ] = MaxReq;  }
    }

    EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

    if (MaxReq == 0) {
        puts(ANSI_COLOR_LIGHTORANGE"Daftar keranjang pesanan produk Anda dari Sektor Industri tengah KOSONG!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(BRIGHTGREEN154"PERHATIAN: Saat ini Anda belum ada membeli produk dari Sektor Industri yang hendak diajukan ke kepada Kemenkeu!");
        puts("...        Anda diperkenankan untuk memesan produk dari Sektor Industri terlebih dahulu..."ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();
    }

    puts("");
    printf(ANSI_COLOR_MAGENTA"Saat ini, tersedia %d PESANAN Anda yang siap untuk didistribusikan kepada Kemenkeu. " ANSI_COLOR_LIGHTGREEN"Distribusikan sekarang?\n", MaxReq);
    puts(ANSI_COLOR_GREEN"... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini..."ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", PeekReq);

    if (PeekReq > 0 && PeekReq <= MaxReq) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
        puts(BRIGHTBLUE158"\nMenu: [3] Distribusi Pemerintah Pusat"ANSI_COLOR_RESET);

        EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
        
        for (size_t i = 0; i < sizeof(AllLinkedRequests)/sizeof(AllLinkedRequests[0]); i++) {
            if (AllLinkedRequests[i] != PeekReq) { GetReq++; }
            else { break; }
            // if (GetReq != (PeekReq - 1)) { if (AllLinkedRequests[i] == 1) { GetReq++; } else { continue; } }
            // else { break; };
        }
        
        strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 3));
        strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 4));
        strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
        CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 6));

        puts("");
        puts("Berikut adalah data keranjang pesanan Anda yang SIAP didistribusikan kepada Kemenkeu:");

        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (GetReq), KDFullName);
            printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
            puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTGREEN"SIAP DIDISTRIBUSIKAN"ANSI_COLOR_RESET);

            strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        
        } else if (CartInfo.Status == 2 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (GetReq), KDFullName);
            printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
            puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET);

            strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

        if (CartInfo.Status == 2) {
            puts("");
            puts(ANSI_COLOR_LIGHTYELLOW"Status Pengajuan: SEDANG DIPROSES");
            puts(ANSI_COLOR_YELLOW":: Sebelumnya Anda telah melakukan pengajuan distribusi barang produksi dari Sektor Industri kepada Kemenkeu...");
            puts(ANSI_COLOR_YELLOW":: Jika Anda ingin membatalkan pengajuan, harap lakukan sesuai perintah berikut ini!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_MAGENTA":: CATATAN PENTING: Apabila Anda tidak menemukan data produk yang bersangkutan ke depannya, berarti");
            puts(ANSI_COLOR_LIGHTMAGENTA":: ...              produk Anda tersebut BERHASIL terjual oleh Kemenkeu dalam skala INTERNASIONAL!");

            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(batalkan pengajuan dengan menyertakan Y atau y, dan N atau n untuk tetap melanjutkan proses pengajuan)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

            if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                puts(BRIGHTBLUE158"\nMenu: [3] Distribusi Pemerintah Pusat"ANSI_COLOR_RESET);

                EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                OverWriteStringAtLine("Temp_"UserCartStore_Keranjang, "1", 0, ((4 + 1) * AllRequestsID[GetReq]) + 6);
                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

                EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                
                strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 3));
                strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 4));
                strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 6));

                puts("");
                puts("Berikut adalah data keranjang pesanan Anda yang siap didistribusikan kepada Kemenkeu:");

                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (GetReq), KDFullName);
                printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
                puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTGREEN"SIAP DIDISTRIBUSIKAN"ANSI_COLOR_RESET);

                strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                
                puts("");
                printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

                puts("");
                puts(ANSI_COLOR_GREEN"Anda telah berhasil membatalkan status pengajuan distribusi Anda kepada Kemenkeu!"ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); UMMFeature03();
           
            } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
                puts("");
                puts(ANSI_COLOR_RED"Anda tetap meneruskan status pengajuan distribusi Anda kepada Kemenkeu!"ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); UMMFeature03();
            }
        }
        
        EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
        
        puts("");
        puts(BRIGHTBLUE159"Berikut adalah hasil pendapatan yang Anda terima apabila pihak Kemenkeu menerima ajuan distribusi Anda:");
        printf(BRIGHTGREEN156"... Harga Total: Rp%'lld.00 " BRIGHTPINK219"(+%0.2f%%) " BRIGHTGREEN156">> " BRIGHTBLUE159"Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine("Temp_"Admin_Kemenkeu, 3)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f))));
        puts(BRIGHTPINK219"... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Kemenkeu!"ANSI_COLOR_RESET);

        EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

        puts("");
        puts(ANSI_COLOR_YELLOW"Setelah melihat data di atas, Anda berhak untuk MENGAJUKAN permintaan distribusi ini ke Kemenkeu. " ANSI_COLOR_LIGHTYELLOW"Ajukan SEKARANG?");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(ketik Y atau y jika setuju, dan N atau n jika tidak setuju)");
        puts(ANSI_COLOR_RED"(jika ingin kembali ke menu sebelumnya, ketik Q atau q)"ANSI_COLOR_RESET);
        AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

        if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
            printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
            puts(BRIGHTBLUE158"\nMenu: [3] Distribusi Pemerintah Pusat"ANSI_COLOR_RESET);

            puts("");
            puts("Berikut adalah data keranjang pesanan Anda yang siap didistribusikan kepada Kemenkeu:");

            EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
            
            strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 3));
            strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 4));
            strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
            CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 6));

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (GetReq), KDFullName);
                printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDJobTitle, KDHeadRegion);
                puts(ANSI_COLOR_LIGHTWHITE"... Status Pengajuan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET);

                strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * AllRequestsID[GetReq]) + 5));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                
                puts("");
                printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

            EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
            EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, true);
            
            EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
            OverWriteStringAtLine("Temp_"UserCartStore_Keranjang, "2", 0, ((4 + 1) * AllRequestsID[GetReq]) + 6);
            EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
            
            puts("");
            puts(BRIGHTBLUE159"Berikut adalah hasil pendapatan yang Anda terima apabila pihak Kemenkeu menerima ajuan distribusi Anda:");
            printf(BRIGHTGREEN156"... Pendapatan Penjualan Anda (sementara): Rp%'lld.00 " BRIGHTBLUE159"<< (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine("Temp_"Admin_Kemenkeu, 3))/100.0f)));
            puts(BRIGHTPINK219"... CATATAN: Anda baru HANYA MENDAPATKAN penghasilan di atas apabila Kemenkeu telah MENYETUJUINYA terlebih dahulu!");
            puts("...          Sebagai informasi, Anda dapat MEMBATALKAN pengajuan ini secara sepihak dari Anda sendiri setelahnya..."ANSI_COLOR_RESET);

            EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);

            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); UMMFeature03();
        
        } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); UMMFeature03();
        } else if   (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); UserMainMenu();
        } else { puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause");
        }
    
    } else if (PeekReq == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();
    } else { CheckInvalidInput = true; UMMFeature03(); }
}

void UMMFeature04(void) {
    FILE *AccessCart;
    SektorIndustri SIList = { 0 };
    Keranjang CartInfo = { 0 };

    char CurrentCartFile[BUFSIZE07] = { 0 }, FinalWrittenReqs[BUFSIZE07] = { 0 };
    char ConfirmStockInput = 0, KDFile[BUFSIZE07] = { 0 }, BeforeSavings[BUFSIZE07] = { 0 }, AfterSavings[BUFSIZE07] = { 0 };
    char CheckStock[BUFSIZE07] = { 0 }, NewProductStock[BUFSIZE07] = { 0 }, ProductName[BUFSIZE07] = { 0 }, *ProductStock = "", *ProductPrice = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, DisplayProductStock[BUFSIZE07] = { 0 }, DisplayProductPrice[BUFSIZE07] = { 0 };
    int MaxStocks = 5, InStocks[5] = { 0, 0, 0, 0, 0 }, AvailableStocks = 0, RecentStatus = 0, KDRequestStatus = 0;
    int PeekStockID = 0, AvailableReqs = 0, SetNewReqs = 0, PeekSI = 0, MaxSI = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        UMMFeature04();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
    printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
    puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);

    EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
    KDRequestStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KDLoggedIn) + 12));
    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

    puts("");
    if (KDRequestStatus == 1) {
        puts(ANSI_COLOR_LIGHTYELLOW"Status Pengajuan: SEDANG DIPROSES");
        puts(ANSI_COLOR_YELLOW":: Sebelumnya Anda telah melakukan pemesanan barang produksi dari Sektor Industri...");
        puts(ANSI_COLOR_YELLOW":: Perhatikan bahwa tindakan tersebut TIDAK DAPAT Anda batalkan kembali, jadi mohon untuk ditunggu konfirmasinya!"ANSI_COLOR_RESET);
        
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();

    } else if (KDRequestStatus == 2) {
        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
        OverWriteStringAtLine("Temp_"User_KepalaDaerah, "0", 0, ((10 + 1) * KDLoggedIn) + 12);
        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

        puts(ANSI_COLOR_LIGHTGREEN"Status Pengajuan: PENGAJUAN DITERIMA");
        puts(ANSI_COLOR_GREEN":: Selamat telah menyelesaikan transaksi barang produksi pesanan Anda dengan Sektor Industri yang bersangkutan...");
        puts(ANSI_COLOR_GREEN":: Saat ini Anda dapat memesan barang produksi Sektor Industri kembali, jadi silakan untuk di-refresh kembali!"ANSI_COLOR_RESET);
        
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UMMFeature04();

    } else if (KDRequestStatus == -1) {
        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
        OverWriteStringAtLine("Temp_"User_KepalaDaerah, "0", 0, ((10 + 1) * KDLoggedIn) + 12);
        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

        EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
        AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

        strcpy(CurrentCartFile, "New_"UserCartStore_Keranjang);
        AccessCart = fopen(CurrentCartFile, "w");
        
        fprintf(AccessCart, "0\n");
        for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
            strcpy(CartInfo.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 3));
            strcpy(CartInfo.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 4));
            strcpy(CartInfo.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 5));
            CartInfo.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * ReqID) + 6));
            CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
            
            if (CartInfo.Status == -1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
                continue;
            } else {
                SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
            }
        } fclose(AccessCart);

        snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
        OverWriteStringAtLine("New_"UserCartStore_Keranjang, FinalWrittenReqs, 0, 1);
        EncryptTextFile("New_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
        system("del Temp_"UserCartStore_Keranjang);

        puts(ANSI_COLOR_LIGHTRED"Status Pengajuan: PENGAJUAN DITOLAK");
        puts(ANSI_COLOR_RED":: Walaupun pengajuan pemesanan Anda ditolak, namun jangan khawatir karena Anda bisa memesan yang lainnya...");
        puts(ANSI_COLOR_RED":: Saat ini Anda dapat memesan barang produksi Sektor Industri kembali, jadi silakan untuk di-refresh kembali!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UMMFeature04();
    }
    
    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
    
    puts("Berikut adalah data dari seluruh Sektor Industri yang tersedia...");
    printf(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int SI = 0; SI < atoi(ReadLine("Temp_"Client_SektorIndustri, 1)); SI++) {
        strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SI) + 3));
        strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SI) + 4));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

        MaxSI++;
        RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SI) + 7));

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (SI + 1), SIList.FullName);
        printf("... Nama Industri: %s\n", SIList.IndustryName);
        if      (RecentStatus == 0)  { puts("... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
        else if (RecentStatus == 1)  { puts("... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }
    }

    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
    
    if (MaxSI > 0) { puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET); }
    else {
        puts("");
        puts(ANSI_COLOR_LIGHTORANGE"Data Sektor Industri belum tersedia!");
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA"Mohon maaf, untuk saat ini belum ada data Sektor Industri yang terdaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lebih lanjutnya dari pihak Sektor Industri yang mendaftar, ");
        puts("... dan dimohon untuk dinantikan dan dipantau menu ini secara berkala..."ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();
    }

    puts("");
    puts(ANSI_COLOR_MAGENTA"Sertakan penomoran Sektor Industri di atas untuk melihat data Sektor Industri yang bersangkutan dengan lebih detail!");
    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, ketik angka 0 untuk kembali ke menu utama Kepala Daerah)"ANSI_COLOR_RESET);
    AcceptInputOption("> Lihat data Sektor Industri: ", PeekSI);

    if (PeekSI > 0 && PeekSI < (MaxSI + 1)) {
        while (true) {
            EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
            RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

            if (RecentStatus == 0) {
                ClearScreen();
                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);
                        
                puts("");
                puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 3));
                strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 4));
                SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                printf("... Nama Industri: %s\n", SIList.IndustryName);
                if      (RecentStatus == 0)  { puts("... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
                else if (RecentStatus == 1)  { puts("... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }
                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                puts("");
                puts(ANSI_COLOR_RED"Mohon maaf, tapi saat ini Sektor Industri yang bersangkutan sedang " ANSI_COLOR_LIGHTRED"TIDAK menerima " ANSI_COLOR_RED"pengajuan kerja sama dengan Kepala Daerah!");
                puts(ANSI_COLOR_GREEN"... Silakan untuk memilih Sektor Industri lainnya..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); UMMFeature04();
            }

            ClearScreen();
            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
            printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
            puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);
                    
            puts("");
            puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

            strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 3));
            strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 4));
            SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

            RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
            printf("... Nama Industri: %s\n", SIList.IndustryName);
            if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
            else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }

            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            for (int SI = 0; SI < MaxStocks; SI++) {
                strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * (PeekSI - 1)) + (8 + SI))));
                CheckStock[strlen(CheckStock) - 1] = '\0';

                if (strcmp(CheckStock, "-, -, -") == 0) { printf(ANSI_COLOR_YELLOW"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
                else {
                    strcpy(ProductName, CheckStock);
                    strtok_r(ProductName, ",", &ProductStock);
                    strtok_r(ProductStock, ",", &ProductPrice);
                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                    AvailableStocks++; InStocks[SI] = 1;
                    if (atoll(ProductStock) >= 100) {
                        printf(BRIGHTBLUE159"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: SANGAT MENCUKUPI"ANSI_COLOR_RESET);
                    } else if (atoll(ProductStock) >= 50 && atoll(ProductStock) < 100) {
                        printf(BRIGHTGREEN156"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: MENCUKUPI"ANSI_COLOR_RESET);
                    } else if (atoll(ProductStock) >= 20 && atoll(ProductStock) < 50) {
                        printf(ANSI_COLOR_ORANGE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: KURANG MENCUKUPI"ANSI_COLOR_RESET);
                    } else if (atoll(ProductStock) >= 0 && atoll(ProductStock) < 20) {
                        printf(ANSI_COLOR_RED"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: TIDAK MENCUKUPI"ANSI_COLOR_RESET);
                    } if (SI != (MaxStocks - 1)) { puts(""); }
                }
            } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

            puts("");
            puts(ANSI_COLOR_MAGENTA"Sertakan penomoran produk ID antara 1 sampai 5 seperti yang tertera di atas!");
            puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, ketik angka 0 untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
            AcceptInputOption("> [1][2][3][4][5] Ajukan Pembelian Produk: ", PeekStockID);

            if (PeekStockID > 0 && PeekStockID <= MaxStocks) {
                while (true) {
                    if (InStocks[PeekStockID - 1] == 1) {
                        ClearScreen();

                        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                        puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);

                        EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                                
                        puts("");
                        puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                        strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 3));
                        strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 4));
                        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                        RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                        printf("... Nama Industri: %s\n", SIList.IndustryName);
                        if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }

                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        for (int SI = 0; SI < MaxStocks; SI++) {
                            strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * (PeekSI - 1)) + (8 + SI))));
                            CheckStock[strlen(CheckStock) - 1] = '\0';

                            if (strchr(CheckStock, '-') != NULL) {
                                if (PeekStockID == (SI + 1)) { printf(ANSI_COLOR_LIGHTWHITE"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
                                else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                            } else {
                                strcpy(ProductName, CheckStock);
                                strtok_r(ProductName, ",", &ProductStock);
                                strtok_r(ProductStock, ",", &ProductPrice);
                                ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                AvailableStocks++;
                                if (PeekStockID == (SI + 1)) {
                                    printf(ANSI_COLOR_LIGHTWHITE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ProductPrice));
                                    strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                } else {
                                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                } if (SI != (MaxStocks - 1)) { puts(""); }
                            }
                        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                        EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                        if (atoll(DisplayProductStock) == 0LL) {
                            puts("");
                            puts(ANSI_COLOR_LIGHTRED":: STATUS: TIDAK MENCUKUPI (STOK PRODUK: 0)");
                            puts(ANSI_COLOR_RED"Maaf, Anda tidak dapat memesan produk yang bersangkutan karena belum diisi kembali oleh Sektor Industri yang bersangkutan!");
                            puts(ANSI_COLOR_YELLOW"Silakan untuk memilih produk lainnya yang masih tersedia..."ANSI_COLOR_RESET);
                            
                            puts("");
                            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                            system("pause"); break;
                        }

                        puts("");
                        puts(BRIGHTGREEN156"Sertakan banyaknya produk yang ingin dipesan kepada Sektor Industri yang bersangkutan!"ANSI_COLOR_RESET);
                        puts(ANSI_COLOR_LIGHTYELLOW"... PERHATIKAN bahwa data yang sudah DISERTAKAN dan DISETUJUI oleh pengguna TIDAK DAPAT DIUBAH ataupun\n... DIBATALKAN kembali selama belum TERKONFIRMASI oleh pihak Sektor Industri yang bersangkutan!");
                        puts(ANSI_COLOR_YELLOW"... Catatan: Jika input dibiarkan kosong, maka nilai default-nya AKAN MENJADI total stok produk saat ini...");
                        puts(ANSI_COLOR_YELLOW"...          Jika nilai input pesanan stok produk tidak sesuai, maka nilai default-nya JUGA AKAN MENJADI\n...          total stok produk saat ini...");
                        printf(BRIGHTGREEN156"[1 <= ??? <= %s]: (sudah jelas)\n"ANSI_COLOR_RESET, DisplayProductStock);
                        
                        puts("");
                        AcceptInputText(BRIGHTPURPLE218"> Banyak stok produk yang ingin dipesan: ", NewProductStock);
                        NewProductStock[strlen(NewProductStock) - 1] = '\0';

                        if (strlen(NewProductStock) == 0 || atoll(NewProductStock) > atoll(DisplayProductStock)) { strcpy(NewProductStock, DisplayProductStock); }                
                        if (atoll(NewProductStock) < 1LL) {
                            puts("");
                            puts(ANSI_COLOR_ORANGE"WARNING: Sesuai dengan penjelasan di atas, nilai stok produk yang dipesan HARUS >= 1!");
                            puts(ANSI_COLOR_LIGHTORANGE"Demi keamaan, harap untuk diulang kembali dan dimohon untuk DIPERHATIKAN perintah yang diminta!"ANSI_COLOR_RESET);
                            puts("");
                            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                            system("pause");

                        } else {
                            snprintf(KDFile, sizeof(KDFile) + 12, "KD - %s.txt", KDFullName);
                            EncryptTextFile(KDFile, "TempKD.txt", -ENCRYPTCODE, false);
                            strcpy(BeforeSavings, ReadLine("TempKD.txt", 1));
                            BeforeSavings[strlen(BeforeSavings) - 1] = '\0';
                            snprintf(AfterSavings, sizeof(AfterSavings), "%lld", atoll(BeforeSavings) - (atoll(DisplayProductPrice) * atoll(NewProductStock)));
                            EncryptTextFile("TempKD.txt", KDFile, ENCRYPTCODE, false);
                            system("del TempKD.txt");

                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                            printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                            puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);

                            EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                                    
                            puts("");
                            puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                            strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 3));
                            strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 4));
                            SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                            RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

                            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                            printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                            printf("... Nama Industri: %s\n", SIList.IndustryName);
                            if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
                            else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }

                            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                            for (int SI = 0; SI < MaxStocks; SI++) {
                                strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * (PeekSI - 1)) + (8 + SI))));
                                CheckStock[strlen(CheckStock) - 1] = '\0';

                                if (strchr(CheckStock, '-') != NULL) {
                                    if (PeekStockID == (SI + 1)) { printf(ANSI_COLOR_LIGHTWHITE"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
                                    else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                                } else {
                                    strcpy(ProductName, CheckStock);
                                    strtok_r(ProductName, ",", &ProductStock);
                                    strtok_r(ProductStock, ",", &ProductPrice);
                                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                    AvailableStocks++;
                                    if (PeekStockID == (SI + 1)) {
                                        printf(ANSI_COLOR_LIGHTWHITE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                        printf("...  Stok Produk: %s\n", ProductStock);
                                        printf("...  Harga Produk (per item): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ProductPrice));
                                        strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                    } else {
                                        printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                        printf("...  Stok Produk: %s\n", ProductStock);
                                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                    } if (SI != (MaxStocks - 1)) { puts(""); }
                                }
                            } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                            puts("");
                            puts(ANSI_COLOR_YELLOW"Apakah Anda sudah yakin dengan banyak stok yang telah Anda pesan?");
                            printf(BRIGHTGREEN156"... Stok produk saat ini dan setelahnya:\n... ... %lld >> %lld\n", atoll(DisplayProductStock), atoll(DisplayProductStock) - atoll(NewProductStock));
                            printf(BRIGHTGREEN156"... Saldo perekonomian Anda saat ini dan setelahnya:\n... ... Rp%'lld.00 >> " BRIGHTBLUE159"Rp%'lld.00 " ANSI_COLOR_RED"(-Rp%'lld.00)\n"ANSI_COLOR_RESET, atoll(BeforeSavings), atoll(AfterSavings), atoll(BeforeSavings) - atoll(AfterSavings));
                            
                            puts("");
                            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(ketik Y atau y apabila sudah yakin, dan N atau n jika ingin dipastikan kembali)"ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(ketik X atau x untuk kembali ke pemilihan produk, dan Q atau q untuk memilih kembali dari awal mula)"ANSI_COLOR_RESET);
                            AcceptCharInput("> Pilihan Anda: ", ConfirmStockInput);

                            if (ConfirmStockInput == 'Y' || ConfirmStockInput == 'y') {
                                snprintf(Belanja.Requester, (sizeof(Belanja.Requester) * 3) + 11, "%s, %s, %s", KDFullName, KDJobTitle, KDHeadRegion);
                                snprintf(Belanja.Accepter, (sizeof(Belanja.Accepter) * 2) + 7, "%s, %s", SIList.FullName, SIList.IndustryName);
                                snprintf(Belanja.ProductInDemand, (sizeof(Belanja.ProductInDemand) * 3) + 13, "%s, %s, %lld", DisplayProductName, NewProductStock, (atoll(DisplayProductPrice) * atoll(NewProductStock)));
                                Belanja.Status = 0;
                                WritePrivateKeranjang(false, 0, false);

                                EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                                OverWriteStringAtLine("Temp_"User_KepalaDaerah, "1", 0, ((10 + 1) * KDLoggedIn) + 12);
                                EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);

                                ClearScreen();
                                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                                printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                                puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);

                                puts("");
                                puts(ANSI_COLOR_LIGHTGREEN"Anda telah berhasil memesan produk distribusi dari Sektor Industri yang bersangkutan!");
                                puts(ANSI_COLOR_GREEN"Dimohon untuk ditunggu informasi lebih lanjut, karena data pengiriman pesanan masihbersifat sementara...");
                                puts(BRIGHTBLUE159"... Pastikan status pesanan Anda untuk melihat bagaimana respons dari pihak Sektor Industri tersebut!"ANSI_COLOR_RESET);

                                puts("");
                                puts("Pesanan Anda meliputi sebagai berikut:");
                                printf(BRIGHTRED216"[KD] Pengajuan dari Yth. %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                                printf(BRIGHTMAGENTA211"[SI] Pengelola kepada Yth. %s, Direktur dari %s.\n", SIList.FullName, SIList.IndustryName);
                                printf(BRIGHTPURPLE218"... 1. Nama Produk: %s\n... 2. Stok Pesanan: %s\n... 3. Harga Total: Rp%'lld.00\n"ANSI_COLOR_RESET, DisplayProductName, NewProductStock, (atoll(DisplayProductPrice) * atoll(NewProductStock)));

                                puts("");
                                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                                system("pause"); UMMFeature04();
                            }
                            
                            else if (ConfirmStockInput == 'N' || ConfirmStockInput == 'n') {
                                puts("");
                                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                                system("pause");
                            } else if (ConfirmStockInput == 'X' || ConfirmStockInput == 'x') {
                                puts("");
                                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                                system("pause"); break;
                            } else if (ConfirmStockInput == 'Q' || ConfirmStockInput == 'q') {
                                puts("");
                                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                                system("pause"); UMMFeature04();
                            }
                        }

                    } else if (InStocks[PeekStockID - 1] == 0) {
                        ClearScreen();

                        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTBLUE159 ANSI_STYLE_BOLD"User :: Kepala Daerah."ANSI_COLOR_RESET);
                        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"... Profil Kepala Daerah: " ANSI_STYLE_UNDERLINE"%s, %s %s.\n"ANSI_COLOR_RESET, KDFullName, KDJobTitle, KDHeadRegion);
                        puts(BRIGHTBLUE158"\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri"ANSI_COLOR_RESET);

                        EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                                
                        puts("");
                        puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                        strcpy(SIList.FullName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 3));
                        strcpy(SIList.IndustryName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 4));
                        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                        RecentStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * (PeekSI - 1)) + 7));

                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                        printf("... Nama Industri: %s\n", SIList.IndustryName);
                        if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITUTUP"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Pembukaan Pengajuan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DIBUKA"ANSI_COLOR_RESET); }

                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        for (int SI = 0; SI < MaxStocks; SI++) {
                            strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * (PeekSI - 1)) + (8 + SI))));
                            CheckStock[strlen(CheckStock) - 1] = '\0';

                            if (strchr(CheckStock, '-') != NULL) {
                                if (PeekStockID == (SI + 1)) { printf(ANSI_COLOR_LIGHTWHITE"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
                                else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                            } else {
                                strcpy(ProductName, CheckStock);
                                strtok_r(ProductName, ",", &ProductStock);
                                strtok_r(ProductStock, ",", &ProductPrice);
                                ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                AvailableStocks++;
                                if (PeekStockID == (SI + 1)) {
                                    printf(ANSI_COLOR_LIGHTWHITE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ProductPrice));
                                    strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                } else {
                                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                } if (SI != (MaxStocks - 1)) { puts(""); }
                            }
                        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                        EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                        puts("");
                        puts(ANSI_COLOR_RED"Mohon maaf, untuk saat ini slot produk hasil Sektor Industri yang bersangkutan MASIH kosong...");
                        puts(ANSI_COLOR_GREEN"... Silakan untuk memilih produk lainnya hasil produksi dari yang bersangkutan!"ANSI_COLOR_RESET);
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); break;
                    }
                }

            } else if (PeekStockID == 0) {
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); UMMFeature04();
            } else { CheckInvalidInput = true; UMMFeature04();  }
        }
    } else if (PeekSI == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); UserMainMenu();
    } else { CheckInvalidInput = true; UMMFeature04();  }
}

void ClientMainMenu(void) {
    int CMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        ClientMainMenu();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
    printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);

    puts("");
    puts(BRIGHTPINK219 ANSI_STYLE_ITALIC "~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"[1] Pendapatan Sektor Industri: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Menampilkan pendapatan total dari hasil produksi industri."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[2] Pengaturan Produksi: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Memampukan perwakilan dari industri untuk mencatat banyak produksi terhadap suatu produk."ANSI_COLOR_RESET);
    puts(BRIGHTPINK219"[3] Pengaturan Kerja Sama dengan Kepala Daerah: " ANSI_COLOR_RESET ANSI_STYLE_ITALIC"Mengatur proses kerja sama dari permintaan kepala daerah tertentu."ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED ANSI_STYLE_BOLD"[0] Keluar..."ANSI_COLOR_RESET);

    puts("");
    puts("Anda dipersilakan untuk memilih dari TIGA (3) opsi di atas... .");
    AcceptInputOption("> Pilihan Anda: ", CMMOption);

    switch (CMMOption) {
        case 1:  { CMMFeature01(); } break;
        case 2:  { CMMFeature02(); } break;
        case 3:  { CMMFeature03(); } break;
        case 0:  { 
            SILoggedIn = 0; SIFullName[0] = 0; SIIndustryName[0] = 0;
            HomeMenu();
        } break;
        default: { CheckInvalidInput = true; ClientMainMenu(); } break;
    }
}

void CMMFeature01(void) {
    char CurrentFileSI[BUFSIZE07], TotalSavings[BUFSIZE07];
    
    ClearScreen();
    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
    printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
    puts(BRIGHTBLUE158"\nMenu: [1] Alur Perekonomian Dana Daerah"ANSI_COLOR_RESET);

    snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 12, "SI - %s.txt", SIFullName);

    EncryptTextFile(CurrentFileSI, "TempSI.txt", -ENCRYPTCODE, false);
    strcpy(TotalSavings, ReadLine("TempSI.txt", 1));
    TotalSavings[strlen(TotalSavings) - 1] = '\0';

    puts("");
    puts("Berikut adalah data akumulasi perekonomian dana industri dari yang bersangkutan:");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    printf(BRIGHTGREEN156"Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
    puts(BRIGHTBLUE159"Pemasukkan (Incomes): ");
    DecryptTextFile("TempSI.txt", false, 0, "TempSI.txt > [+]"); puts("");
    puts(BRIGHTMAGENTA211"Pengeluaran (Expenses): TIDAK ADA PENGELUARAN BAGI SEKTOR INDUSTRI");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    EncryptTextFile("TempSI.txt", CurrentFileSI, ENCRYPTCODE, true);

    puts("");
    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
    system("pause");
    ClientMainMenu();
}

void CMMFeature02(void) {
    char CheckStock[BUFSIZE07] = { 0 }, FinalWrittenProduct[BUFSIZE07] = { 0 };
    char ProductName[BUFSIZE07] = { 0 }, *ProductStock = "", *ProductPrice = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, DisplayProductStock[BUFSIZE07] = { 0 }, DisplayProductPrice[BUFSIZE07] = { 0 };
    char NewProductName[BUFSIZE07] = { 0 }, NewProductStock[BUFSIZE07] = { 0 }, NewProductPrice[BUFSIZE07] = { 0 };
    int InStocks[5] = { 0, 0, 0, 0, 0 };
    int AvailableStocks = 0, MaxStocks = 5, PeekStockID = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        CMMFeature02();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
    printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
    puts(BRIGHTPINK219"\nMenu: [2] Pengaturan Produksi"ANSI_COLOR_RESET);

    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);

    puts("");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    for (int SI = 0; SI < MaxStocks; SI++) {
        strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SILoggedIn) + (8 + SI))));
        CheckStock[strlen(CheckStock) - 1] = '\0';

        if (strcmp(CheckStock, "-, -, -") == 0) { printf(ANSI_COLOR_YELLOW"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
        else {
            strcpy(ProductName, CheckStock);
            strtok_r(ProductName, ",", &ProductStock);
            strtok_r(ProductStock, ",", &ProductPrice);
            ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

            AvailableStocks++; InStocks[SI] = 1;
            if (atoll(ProductStock) >= 100) {
                printf(BRIGHTBLUE159"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                printf("...  Stok Produk: %s\n", ProductStock);
                printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                puts(ANSI_STYLE_BOLD"STATUS: SANGAT MENCUKUPI"ANSI_COLOR_RESET);
            } else if (atoll(ProductStock) >= 50 && atoll(ProductStock) < 100) {
                printf(BRIGHTGREEN156"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                printf("...  Stok Produk: %s\n", ProductStock);
                printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                puts(ANSI_STYLE_BOLD"STATUS: MENCUKUPI"ANSI_COLOR_RESET);
            } else if (atoll(ProductStock) >= 20 && atoll(ProductStock) < 50) {
                printf(ANSI_COLOR_ORANGE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                printf("...  Stok Produk: %s\n", ProductStock);
                printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                puts(ANSI_STYLE_BOLD"STATUS: KURANG MENCUKUPI"ANSI_COLOR_RESET);
            } else if (atoll(ProductStock) >= 0 && atoll(ProductStock) < 20) {
                printf(ANSI_COLOR_RED"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                printf("...  Stok Produk: %s\n", ProductStock);
                printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                puts(ANSI_STYLE_BOLD"STATUS: TIDAK MENCUKUPI"ANSI_COLOR_RESET);
            } if (SI != (MaxStocks - 1)) { puts(""); }
        }
    } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    
    ProductName[0] = 0; ProductStock = ""; ProductPrice = "";
    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

    puts("");
    if (AvailableStocks >= 0 && AvailableStocks < 3) {
        printf(ANSI_COLOR_MAGENTA"Tersedia " ANSI_COLOR_LIGHTGREEN"%d " ANSI_COLOR_MAGENTA"dari " ANSI_COLOR_LIGHTMAGENTA"%d " ANSI_COLOR_MAGENTA"stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts(ANSI_COLOR_LIGHTGREEN"... TAMBAHKAN produk hasil industri baru?\n");
        puts(ANSI_COLOR_PINK ANSI_STYLE_ITALIC"(ketik angka bebas dari [1] hingga [5] untuk dilakukan pengisian data produk baru)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, silakan ketik [0] untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
        AcceptInputOption("> Pilihan Anda: ", PeekStockID);

    } else if (AvailableStocks >= 3 && AvailableStocks < 5) {
        printf(ANSI_COLOR_MAGENTA"Tersedia " ANSI_COLOR_LIGHTYELLOW"%d " ANSI_COLOR_MAGENTA"dari " ANSI_COLOR_LIGHTMAGENTA"%d " ANSI_COLOR_MAGENTA"stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts(ANSI_COLOR_LIGHTYELLOW"... TAMBAHKAN produk hasil industri baru atau PERBAHARUI data produk yang sudah ada?\n");
        puts(ANSI_COLOR_PINK ANSI_STYLE_ITALIC"(ketik angka penomoran yang sesuai dengan yang telah berlaku seperti di atas)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, silakan ketik [0] untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
        AcceptInputOption("> Pilihan Anda: ", PeekStockID);
    
    } else if (AvailableStocks == 5) {
        printf(ANSI_COLOR_MAGENTA"Tersedia " ANSI_COLOR_LIGHTRED"%d " ANSI_COLOR_MAGENTA"dari " ANSI_COLOR_LIGHTMAGENTA"%d " ANSI_COLOR_MAGENTA"stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts(ANSI_COLOR_LIGHTRED"... HAPUSKAN produk hasil industri lama atau PERBAHARUI data produk yang sudah ada?\n");
        puts(ANSI_COLOR_PINK ANSI_STYLE_ITALIC"(ketik angka penomoran yang sesuai dengan yang telah berlaku seperti di atas)");
        puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika tidak, silakan ketik [0] untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
        AcceptInputOption("> Pilihan Anda: ", PeekStockID);
    }

    if (PeekStockID > 0 && PeekStockID < 6) {
        while (true) {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
            printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
            puts(BRIGHTPINK219"\nMenu: [2] Pengaturan Produksi"ANSI_COLOR_RESET);

            EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
            
            puts("");
            puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            for (int SI = 0; SI < MaxStocks; SI++) {
                strcpy(CheckStock, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SILoggedIn) + (8 + SI))));
                CheckStock[strlen(CheckStock) - 1] = '\0';

                if (strchr(CheckStock, '-') != NULL) {
                    if (PeekStockID == (SI + 1)) { printf(ANSI_COLOR_LIGHTWHITE"[%d]: Stok produk industri masih kosong\n"ANSI_COLOR_RESET, (SI + 1)); }
                    else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                } else {
                    strcpy(ProductName, CheckStock);
                    strtok_r(ProductName, ",", &ProductStock);
                    strtok_r(ProductStock, ",", &ProductPrice);
                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                    AvailableStocks++;
                    if (PeekStockID == (SI + 1)) {
                        printf(ANSI_COLOR_LIGHTWHITE"[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n"ANSI_COLOR_RESET, atoll(ProductPrice));
                        strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                    } else {
                        printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                    } if (SI != (MaxStocks - 1)) { puts(""); }
                }
            } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
            
            ProductName[0] = 0; ProductStock = ""; ProductPrice = "";
            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
            
            puts("");
            if (InStocks[PeekStockID - 1] == 1) {
                puts(BRIGHTGREEN156"CATATAN:  Biarkan sesi input kosong apabila data yang bersangkutan TIDAK ingin diubah!");
                puts(BRIGHTPURPLE218"...       Jika produck yang bersnagkutan ingin DIHAPUS, maka sertakan tanda '-' di setiap sesi input");
                puts(BRIGHTPURPLE218"...       berikut (tanpa tanda petiknya) agar produk tersebut berhasil dihapuskan...");
                puts(BRIGHTBLUE159"TAMBAHAN: Perlu diingat hanya sertakan SATU TANDA '-' saja, jika tidak akan dianggap INVALID secara keseluruhan!");
                
                puts("");
                puts(BRIGHTBLUE159"[Texts]: Input harus berupa teks");
                puts("[>= N]: Bilangan bulat positif; Angka N termasuk"ANSI_COLOR_RESET);

                puts("");
                AcceptInputText(BRIGHTPURPLE212"[ Texts ] Nama produk BARU yang bersangkutan: ", NewProductName);
                AcceptInputText(BRIGHTPURPLE218"[>=    1] Stok total produk BARU yang bersangkutan: ", NewProductStock);
                AcceptInputText(BRIGHTPURPLE218"[>= 1000] Harga per produk BARU yang bersangkutan: ", NewProductPrice);
                NewProductName[strlen(NewProductName) - 1] = '\0'; NewProductStock[strlen(NewProductStock) - 1] = '\0'; NewProductPrice[strlen(NewProductPrice) - 1] = '\0';

                if (strcmp(NewProductName, "-") == 0 && strcmp(NewProductStock, "-") == 0 && strcmp(NewProductPrice, "-") == 0) {
                    snprintf(FinalWrittenProduct, sizeof(FinalWrittenProduct), "-, -, -");
                    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                    OverWriteStringAtLine("Temp_"Client_SektorIndustri, FinalWrittenProduct, 0, (((10 + 1) * SILoggedIn) + (8 + (PeekStockID - 1))));
                    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"Penghapusan data produk yang bersangkutan TELAH BERHASIL!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause"); CMMFeature02();
                
                } else if (strlen(NewProductName) > 1 && strchr(NewProductName, '-')) {
                    puts("");
                    puts(ANSI_COLOR_RED"ERROR: Maaf, nama produk yang mengandung tanga '-' kami anggap TIDAK VALID dikarekanakan SINTAKS penggunaan");
                    puts("...    tanda '-' hanya untuk PENGHAPUSAN data produk yang bersangkutan, jadi mohon pengertiannya!");
                    puts(ANSI_COLOR_YELLOW":: Anda akan dibawa kembali ke pengisian data produk industri..."ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");

                } else if (strcmp(NewProductName, "-") != 0 && strcmp(NewProductStock, "-") != 0 && strcmp(NewProductPrice, "-") != 0) {
                    if (strlen(NewProductName) == 0)  { strcpy(NewProductName, DisplayProductName);   }
                    if (strlen(NewProductStock) == 0) { strcpy(NewProductStock, DisplayProductStock); }
                    if (strlen(NewProductPrice) == 0) { strcpy(NewProductPrice, DisplayProductPrice); }
                    
                    if (atoll(NewProductStock) < 1LL || strchr(NewProductStock, '.') != NULL) {
                        puts("");
                        puts(ANSI_COLOR_ORANGE"PERHATIAN: Nilai stok total produk harus LEBIH DARI SAMA DENGAN 1!\n:: Melakukan penyetelan ulang ke nomina 1 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductStock, "1");
                    } if (atoll(NewProductPrice) < 1000LL || strchr(NewProductPrice, '.') != NULL) {
                        puts("");
                        puts(ANSI_COLOR_ORANGE"PERHATIAN: Nilai harga per produk harus LEBIH DARI SAMA DENGAN 1000!\n:: Melakukan penyetelan ulang ke nomina 1000 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductPrice, "1000");
                    }

                    snprintf(FinalWrittenProduct, (sizeof(FinalWrittenProduct) * 3) + 4, "%s, %s, %s", NewProductName, NewProductStock, NewProductPrice);
                    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                    OverWriteStringAtLine("Temp_"Client_SektorIndustri, FinalWrittenProduct, 0, (((10 + 1) * SILoggedIn) + (8 + (PeekStockID - 1))));
                    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                    puts("");
                    puts(ANSI_COLOR_LIGHTGREEN"Data produk industri yang bersangkutan telah diperbaharui!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    CMMFeature02();
                
                } else {
                    puts("");
                    puts(ANSI_COLOR_RED"ERROR: Sekali lagi, dimohon jika ingin dilakukan penghapusan data produk, pastikan SINTAKS INPUT-NYA TELAH SESUAI");
                    puts("...    dengan yang diminta agar tidak terjadi kesalahan input data, jadi mohon pengertiannya!");
                    puts(ANSI_COLOR_YELLOW":: Anda akan dibawa kembali ke pengisian data produk industri..."ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                }

            } else if (InStocks[PeekStockID - 1] == 0) {
                puts(ANSI_COLOR_LIGHTYELLOW"PERHATIKAN apabila terdapat sesi input yang kosong, maka Anda harus mengelola data KEMBALI DARI SEMULA!");
                puts(ANSI_COLOR_YELLOW"... Mohon perhatiannya, terutama dalam pengisian Nama Produk, dan teruntuk Stok beserta Harga Produk akan");
                puts("... ada penyetelannya sendiri ke nomina default mereka masing-masing..."ANSI_COLOR_RESET);
                puts(BRIGHTBLUE159"[Texts]: Input harus berupa teks");
                puts("[>= N]: Bilangan bulat positif; Angka N termasuk"ANSI_COLOR_RESET);

                puts("");
                AcceptInputText(BRIGHTPURPLE212"[ Texts ] Nama Produk: ", NewProductName);
                AcceptInputText(BRIGHTPURPLE218"[>=    1] Stok Total Produk: ", NewProductStock);
                AcceptInputText(BRIGHTPURPLE218"[>= 1000] Harga per Produk: ", NewProductPrice);
                NewProductName[strlen(NewProductName) - 1] = '\0'; NewProductStock[strlen(NewProductStock) - 1] = '\0'; NewProductPrice[strlen(NewProductPrice) - 1] = '\0';

                if (strlen(NewProductName) == 0) {
                    puts("");
                    puts(ANSI_COLOR_RED"ERROR: Sekali lagi, dimohon untuk tidak mengosongkan sesi input Nama Produk yang bersangkutan dikarenakan");
                    puts("...    saat ini Anda tengah mengisi data baru, jadi mohon pengertiannya!");
                    puts(ANSI_COLOR_YELLOW":: Anda akan dibawa kembali ke pengisian data produk industri..."ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");

                } else if ((strcmp(NewProductName, "-") == 0 && strcmp(NewProductStock, "-") == 0 && strcmp(NewProductPrice, "-") == 0)) {
                    puts("");
                    puts(ANSI_COLOR_RED"ERROR: Maaf, kami tidak menerima PENGHAPUSAN data produk industri apabila data yang bersangkutan masih");
                    puts("...    kosong dikarenakan belum ada diisi oleh apapun dari pihak Anda, jadi mohon pengertiannya!");
                    puts(ANSI_COLOR_YELLOW":: Anda akan dibawa kembali ke pengisian data produk industri..."ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                 
                } else if (strlen(NewProductName) > 1 && strchr(NewProductName, '-')) {
                    puts("");
                    puts(ANSI_COLOR_RED"ERROR: Maaf, nama produk yang mengandung tanga '-' kami anggap TIDAK VALID dikarekanakan SINTAKS penggunaan");
                    puts("...    tanda '-' hanya untuk PENGHAPUSAN data produk yang bersangkutan, jadi mohon pengertiannya!");
                    puts(ANSI_COLOR_YELLOW":: Anda akan dibawa kembali ke pengisian data produk industri..."ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");

                } else { 
                    if (atoll(NewProductStock) < 1LL || strchr(NewProductStock, '.') != NULL) {
                        puts("");
                        puts(ANSI_COLOR_ORANGE"PERHATIAN: Nilai stok total produk harus LEBIH DARI SAMA DENGAN 1!\n:: Melakukan penyetelan ulang ke nomina 1 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductStock, "1");
                    } if (atoll(NewProductPrice) < 1000LL || strchr(NewProductPrice, '.') != NULL) {
                        puts("");
                        puts(ANSI_COLOR_ORANGE"PERHATIAN: Nilai harga per produk harus LEBIH DARI SAMA DENGAN 1000!\n:: Melakukan penyetelan ulang ke nomina 1000 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductPrice, "1000");
                    }

                    snprintf(FinalWrittenProduct, (sizeof(FinalWrittenProduct) * 3) + 4, "%s, %s, %s", NewProductName, NewProductStock, NewProductPrice);
                    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                    OverWriteStringAtLine("Temp_"Client_SektorIndustri, FinalWrittenProduct, 0, (((10 + 1) * SILoggedIn) + (8 + (PeekStockID - 1))));
                    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                    puts("");
                    puts(ANSI_COLOR_LIGHTGREEN"Data produk industri BARU telah ditambahkan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    CMMFeature02();
                }
            }
        }

    } else if (PeekStockID == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); ClientMainMenu();
    } else { CheckInvalidInput = true; CMMFeature02(); }
}

void CMMFeature03(void) {
    KepalaDaerah KDList = { 0 };
    FILE *AccessKDSavings, *AccessSISavings; // *AccessCart;

    char DisplayKDRequests[BUFSIZE10][BUFSIZE07] = { 0 };
    char UpdateStatus; // KDFileName[BUFSIZE07];
    char ProductName[BUFSIZE07] = { 0 }, *ProductStock, *ProductPrice, DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock, *DisplayProductPrice;
    char CurrentKDFile[BUFSIZE07] = { 0 }, FinalKDSavings[BUFSIZE07] = { 0 };
    char CurrentSIFile[BUFSIZE07] = { 0 }, FinalSISavings[BUFSIZE07] = { 0 };
    // int StatusList[BUFSIZE10] = { 0 };
    int GetStockID = 0, RecentStatus = 0, SIStandaloneStatus = 0, OCManaging = 0;
    int AvailableReqs = 0, AvailableKDs = 0, PeekKD = 0, MaxReq = 0; // PeekReq = 0, MaxKD = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);

        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause");
        CheckInvalidInput = false;
        CMMFeature03();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
    printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
    puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

    EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
    SIStandaloneStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SILoggedIn) + 7));
    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

    puts("");
    printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
    if      (SIStandaloneStatus == 0) { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
    else if (SIStandaloneStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }
    puts(ANSI_COLOR_YELLOW"... Pengaturan di atas dapat Anda atur dari pilihan kedua menu berikut!"ANSI_COLOR_RESET);

    puts("");
    puts(BRIGHTBLUE159"[1] BUKA/TUTUP jasa pengajuan kerja sama Sektor Industri dengan Kepala Daerah");
    puts(BRIGHTBLUE159"[2] KELOLA pelbagai pengajuan kerja sama Sektor Industri dari masing-masing Kepala Daerah"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_RED"[0] Kembali..."ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", OCManaging);
    
    if (OCManaging == 1) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

        puts("");
        printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
        if (SIStandaloneStatus == 0) {
            puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);
            
            puts("");
            puts(ANSI_COLOR_CYAN"Apakah Anda menghendaki untuk MEMBUKA peluang pengajuan kerja sama dengan Kepala Daerah?");
            puts(ANSI_STYLE_ITALIC"(cukup sertakan Y atau y jika setuju, dan N atau n untuk tetap menutupnya)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                ClearScreen();

                EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                OverWriteStringAtLine("Temp_"Client_SektorIndustri, "1", 0, ((10 + 1) * SILoggedIn) + 7);
                SIStandaloneStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SILoggedIn) + 7));
                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
                printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
                puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
                if (SIStandaloneStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
                else if (SIStandaloneStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

                puts("");
                puts(ANSI_COLOR_GREEN"Anda telah MEMBUKA sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); CMMFeature03();

            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                puts("");
                puts(ANSI_COLOR_RED"Anda tetap MENUTUP sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); CMMFeature03();
            }

        } else if (SIStandaloneStatus == 1) {
            puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET);
        
            puts("");
            puts(ANSI_COLOR_CYAN"Apakah Anda menghendaki untuk MENUTUP peluang pengajuan kerja sama dengan Kepala Daerah?");
            puts(ANSI_STYLE_ITALIC"(cukup sertakan Y atau y jika setuju, dan N atau n untuk tetap menutupnya)"ANSI_COLOR_RESET);
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                ClearScreen();

                EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                OverWriteStringAtLine("Temp_"Client_SektorIndustri, "0", 0, ((10 + 1) * SILoggedIn) + 7);
                SIStandaloneStatus = atoi(ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SILoggedIn) + 7));
                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);

                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
                printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
                puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
                if (SIStandaloneStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
                else if (SIStandaloneStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

                puts("");
                puts(ANSI_COLOR_RED"Anda telah MENUTUP sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); CMMFeature03();

            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                puts("");
                puts(ANSI_COLOR_GREEN"Anda tetap MEMBUKA sesi peluang pengajuan kerja sama dengan Kepala Daerah..."ANSI_COLOR_RESET);
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause"); CMMFeature03();
            }
        }

    } else if (OCManaging == 2 && SIStandaloneStatus == 1) {
        // char DisplayKDFullName[BUFSIZE07] = { 0 }, *DisplayKDJobTitle, *DisplayKDHeadRegion;

        ClearScreen();
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
        EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
        AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
        AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));
        
        puts("");
        puts("Berikut adalah data pengajuan kerja sama dari pelbagai Kepala Daerah dengan yang bersangkutan...");
        
        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
        for (int REQ = 0; REQ < AvailableReqs; REQ++) {
            strcpy(Belanja.Requester, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 3));
            strcpy(Belanja.Accepter, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 4));
            strcpy(Belanja.ProductInDemand, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 5));
            Belanja.Status = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * REQ) + 6));
            Belanja.Requester[strlen(Belanja.Requester) - 1] = '\0'; Belanja.Accepter[strlen(Belanja.Accepter) - 1] = '\0'; Belanja.ProductInDemand[strlen(Belanja.ProductInDemand) - 1] = '\0';
            
            for (int KD = 0; KD < AvailableKDs; KD++) {
                if (strstr(Belanja.Accepter, SIFullName) != NULL && strstr(Belanja.Accepter, SIIndustryName)) {
                    MaxReq++;

                    strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                    strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                    strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                    KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';
                    RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 12));

                    if (Belanja.Status == 0 && strstr(Belanja.Requester, KDList.FullName) != NULL && strstr(Belanja.Requester, KDList.JobTitle) != NULL && strstr(Belanja.Requester, KDList.HeadRegion) != NULL) {
                        printf("[%03d] Nama Lengkap: %s\n", (REQ + 1), KDList.FullName);
                        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                        else if (RecentStatus == 1)  { puts("... Status Permintaan: " ANSI_COLOR_YELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 2)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                        else if (RecentStatus == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

                        // StatusList[KD] = RecentStatus;
                        strcpy(DisplayKDRequests[REQ], Belanja.Requester);
                        // break;

                    } else if ((Belanja.Status == 1 || Belanja.Status == -1) && strstr(Belanja.Requester, KDList.FullName) != NULL && strstr(Belanja.Requester, KDList.JobTitle) != NULL && strstr(Belanja.Requester, KDList.HeadRegion) != NULL) {
                        printf("[%03d] Nama Lengkap: %s\n", (REQ + 1), KDList.FullName);
                        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                        if      (Belanja.Status == 1)  { puts("... Status Permintaan: " ANSI_COLOR_GREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                        else if (Belanja.Status == -1) { puts("... Status Permintaan: " ANSI_COLOR_RED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

                        // StatusList[KD] = RecentStatus;
                        strcpy(DisplayKDRequests[REQ], Belanja.Requester);
                        // break;
                    
                    } else { continue; }
                }
            } if (MaxReq != 0) { if (REQ + 1 != AvailableReqs) { puts(""); } }
        } 
        
        if (MaxReq != 0) { puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET); }
        else             { puts(ANSI_COLOR_LIGHTORANGE"Data pengajuan dari Kepala Daerah kosong!"ANSI_COLOR_RESET); puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET); }

        EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
        EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
        
        if (MaxReq > 0) {
            puts("");
            puts(ANSI_COLOR_LIGHTMAGENTA"Kepada siapa pengajuan kerja sama dari Kepala Daerah pada data di atas yang ingin Anda KELOLA lebih lanjut?");
            puts(ANSI_COLOR_YELLOW ANSI_STYLE_ITALIC"(kondisi input disesuaikan sesuai penomoran Kepala Daerah di atas)"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(jika ingin kembali ke menu sebelumnya, ketik 0 pada input di bawah)"ANSI_COLOR_RESET);
            AcceptInputOption("> Pilihan Anda: ", PeekKD);

            if (PeekKD > 0 && PeekKD <= AvailableReqs) {
                ClearScreen();
                
                puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
                printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
                puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
                AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

                puts("");
                puts("Berikut adalah data pengajuan kerja sama dari pelbagai Kepala Daerah dengan yang bersangkutan...");
                
                puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                for (int KD = 0; KD < AvailableKDs; KD++) {
                    strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                    strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                    strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                    KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                    if (strstr(DisplayKDRequests[PeekKD - 1], KDList.FullName) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.JobTitle) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.HeadRegion) != NULL) {
                        printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, (KD + 1), KDList.FullName);
                        printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);

                        RecentStatus = atoi(ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * (PeekKD - 1)) + 6));
                        if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                        else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                        else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

                        strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * (PeekKD - 1)) + 5));
                        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                        
                        puts("");
                        printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                        break;
                    }
                }

                int MaxStocks = 5;
                for (int ID = 0; ID < MaxStocks; ID++) {
                    strcpy(ProductName, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SILoggedIn) + (8 + ID)));
                    ProductName[strlen(ProductName) - 1] = '\0';

                    if (strstr(ProductName, DisplayProductName) != NULL) {
                        strtok_r(ProductName, ",", &ProductStock); ProductStock = TrimWhiteSpaces(ProductStock);
                        strtok_r(ProductStock, ",", &ProductPrice); ProductPrice = TrimWhiteSpaces(ProductPrice);
                        GetStockID = ID;
                        break;
                    }
                }

                EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);

                // if (RecentStatus == 0) {
                //     // Not possibly going to happen though...
                //     // If ever falls here, it means that there's a bug going on!
                //     puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                //     puts(ANSI_COLOR_LIGHTYELLOW"Status Pengajuan: -");
                //     puts(ANSI_COLOR_YELLOW":: Tidak ada informasi pengajuan lebih lanjut dari Kepala Daerah yang bersangkutan...");
                //     puts(ANSI_COLOR_YELLOW":: ..."ANSI_COLOR_RESET);
                //     puts(""); system("pause"); CMMFeature03();
                // } else
                if (RecentStatus == 1) {
                    puts("====================================================================================================\n"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_LIGHTGREEN"Status Pengajuan: PENGAJUAN DITERIMA");
                    puts(ANSI_COLOR_GREEN":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                    puts(ANSI_COLOR_GREEN":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!"ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause"); CMMFeature03();

                } else if (RecentStatus == -1) {
                    puts("====================================================================================================\n"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_LIGHTRED"Status Pengajuan: PENGAJUAN DITOLAK");
                    puts(ANSI_COLOR_RED":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan");
                    puts(ANSI_COLOR_RED":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!"ANSI_COLOR_RESET);
                    
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause"); CMMFeature03();
                
                } else if (RecentStatus == 0) {
                    puts("==================================================" ANSI_COLOR_LIGHTCYAN"=================================================="ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_LIGHTCYAN"Produk Sektor Industri yang bersangkutan:"ANSI_COLOR_RESET);

                    if ((atoll(ProductStock) - atoll(DisplayProductStock)) >= 100) {
                        printf(BRIGHTBLUE159"... Nama Produk: %s\n", ProductName);
                        if      (RecentStatus == 0)  { printf("... Stok Produk: %lld >> %lld\n", atoll(ProductStock), (atoll(ProductStock) - atoll(DisplayProductStock))); }
                        else if (RecentStatus == 1)  { printf("... Stok Produk: %lld >> %lld (-%lld)\n", atoll(ProductStock) + atoll(DisplayProductStock), atoll(ProductStock), atoll(DisplayProductStock)); }
                        else if (RecentStatus == -1) { printf("... Stok Produk: %lld >> %lld (-%d)\n", atoll(ProductStock), atoll(ProductStock), 0); }
                        printf("... Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: SANGAT MENCUKUPI"ANSI_COLOR_RESET);
                    } else if ((atoll(ProductStock) - atoll(DisplayProductStock)) >= 50 && (atoll(ProductStock) - atoll(DisplayProductStock)) < 100) {
                        printf(BRIGHTGREEN156"... Nama Produk: %s\n", ProductName);
                        if      (RecentStatus == 0)  { printf("... Stok Produk: %lld >> %lld\n", atoll(ProductStock), (atoll(ProductStock) - atoll(DisplayProductStock))); }
                        else if (RecentStatus == 1)  { printf("... Stok Produk: %lld >> %lld (-%lld)\n", atoll(ProductStock) + atoll(DisplayProductStock), atoll(ProductStock), atoll(DisplayProductStock)); }
                        else if (RecentStatus == -1) { printf("... Stok Produk: %lld >> %lld (-%d)\n", atoll(ProductStock), atoll(ProductStock), 0); }
                        printf("... Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: MENCUKUPI"ANSI_COLOR_RESET);
                    } else if ((atoll(ProductStock) - atoll(DisplayProductStock)) >= 20 && (atoll(ProductStock) - atoll(DisplayProductStock)) < 50) {
                        printf(ANSI_COLOR_ORANGE"... Nama Produk: %s\n", ProductName);
                        if      (RecentStatus == 0)  { printf("... Stok Produk: %lld >> %lld\n", atoll(ProductStock), (atoll(ProductStock) - atoll(DisplayProductStock))); }
                        else if (RecentStatus == 1)  { printf("... Stok Produk: %lld >> %lld (-%lld)\n", atoll(ProductStock) + atoll(DisplayProductStock), atoll(ProductStock), atoll(DisplayProductStock)); }
                        else if (RecentStatus == -1) { printf("... Stok Produk: %lld >> %lld (-%d)\n", atoll(ProductStock), atoll(ProductStock), 0); }
                        printf("... Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: KURANG MENCUKUPI"ANSI_COLOR_RESET);
                    } else if ((atoll(ProductStock) - atoll(DisplayProductStock)) < 20) {
                        printf(ANSI_COLOR_RED"... Nama Produk: %s\n", ProductName);
                        if      (RecentStatus == 0)  { printf("... Stok Produk: %lld >> %lld\n", atoll(ProductStock), (atoll(ProductStock) - atoll(DisplayProductStock))); }
                        else if (RecentStatus == 1)  { printf("... Stok Produk: %lld >> %lld (-%lld)\n", atoll(ProductStock) + atoll(DisplayProductStock), atoll(ProductStock), atoll(DisplayProductStock)); }
                        else if (RecentStatus == -1) { printf("... Stok Produk: %lld >> %lld (-%d)\n", atoll(ProductStock), atoll(ProductStock), 0); }
                        printf("... Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        puts(ANSI_STYLE_BOLD"STATUS: TIDAK MENCUKUPI"ANSI_COLOR_RESET);
                    } puts(ANSI_COLOR_LIGHTCYAN"===================================================================================================="ANSI_COLOR_RESET);

                    if ((atoll(ProductStock) - atoll(DisplayProductStock)) < 0) {
                        puts("");
                        puts(ANSI_COLOR_LIGHTORANGE"Maaf, saat ini stok produk Anda yang dipesan oleh Kepala Daerah yang bersangkutan tidak memenuhi!");
                        puts(ANSI_COLOR_YELLOW"Mohon diperhatikan kembali lebih lanjut mengenai ketersediaan stok produk industri...");
                        puts("... Anda akan di bawa kembali ke menu sebelumnya..."ANSI_COLOR_RESET);
                        
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); CMMFeature03();
                    }

                    puts(ANSI_COLOR_CYAN"Saat ini Kepala Daerah yang bersangkutan tengah dalam masa pemrosesan pengajuan kerja sama dari pihak Anda.");
                    puts(ANSI_STYLE_BOLD BRIGHTPINK219"... Berdasarkan pemesanan yang dibuatnya di atas, apakah Anda yakin untuk MENERIMA pengajuan dari beliau, atau harus MENOLAKNYA?");
                    puts("... Tidak akan ada pengeluaran yang dihasilkan selama proses ini berlangsung!");
                    
                    puts("");
                    puts(ANSI_COLOR_GREEN ANSI_STYLE_ITALIC"(sertakan Y atau y untuk menyetujui pengajuan, dan N atau n untuk menolak pengajuan)"ANSI_COLOR_RESET);
                    puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC"(sertakan Q atau q untuk kembali ke menu sebelumnya)"ANSI_COLOR_RESET);
                    AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

                    if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                        ClearScreen();
                        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
                        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
                        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                        EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                        EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                        AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
                        AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

                        puts("");
                        puts("Berikut adalah data pengajuan kerja sama dari Kepala Daerah dengan yang bersangkutan...");
                        
                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        for (int KD = 0; KD < AvailableKDs; KD++) {
                            strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                            strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                            strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                            KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                            if (strstr(DisplayKDRequests[PeekKD - 1], KDList.FullName) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.JobTitle) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.HeadRegion) != NULL) {
                                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, PeekKD, KDList.FullName);
                                printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);

                                OverWriteStringAtLine("Temp_"User_KepalaDaerah, "2", 0, ((10 + 1) * KD) + 12);
                                OverWriteStringAtLine("Temp_"UserCartStore_Keranjang, "1", 0, ((4 + 1) * (PeekKD - 1)) + 6);

                                RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 12));
                                if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: -"ANSI_COLOR_RESET); }
                                else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                                else if (RecentStatus == 2)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                                else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

                                strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * (PeekKD - 1)) + 5));
                                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                                
                                puts("");
                                printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

                                snprintf(CurrentKDFile, sizeof(CurrentKDFile) + 12, "KD - %s.txt", KDList.FullName);
                                EncryptTextFile(CurrentKDFile, "TempKD.txt", -ENCRYPTCODE, false);
                                AccessKDSavings = fopen("TempKD.txt", "a");
                                fprintf(AccessKDSavings, "[-] Rp%'lld.00: Pembelian produk (%s: %s) item, dari Yth. %s, %s\n", atoll(DisplayProductPrice), DisplayProductName, DisplayProductStock, SIFullName, SIIndustryName);
                                fclose(AccessKDSavings);
                                snprintf(FinalKDSavings, sizeof(FinalKDSavings), "%lld", atoll(ReadLine("TempKD.txt", 1)) - atoll(DisplayProductPrice));
                                OverWriteStringAtLine("TempKD.txt", FinalKDSavings, 0, 1);
                                EncryptTextFile("TempKD.txt", CurrentKDFile, ENCRYPTCODE, false); system("del TempKD.txt");
                                CurrentKDFile[0] = 0;

                                snprintf(CurrentSIFile, sizeof(CurrentSIFile) + 12, "SI - %s.txt", SIFullName);
                                EncryptTextFile(CurrentSIFile, "TempSI.txt", -ENCRYPTCODE, false);
                                AccessSISavings = fopen("TempSI.txt", "a");
                                fprintf(AccessSISavings, "[+] Rp%'lld.00: Penjualan produk (%s: %s) item, kepada Yth. %s, %s %s\n", atoll(DisplayProductPrice), DisplayProductName, DisplayProductStock, KDList.FullName, KDList.JobTitle, KDList.HeadRegion);
                                fclose(AccessSISavings);
                                snprintf(FinalSISavings, sizeof(FinalSISavings), "%lld", atoll(ReadLine("TempSI.txt", 1)) + atoll(DisplayProductPrice));
                                OverWriteStringAtLine("TempSI.txt", FinalSISavings, 0, 1);
                                EncryptTextFile("TempSI.txt", CurrentSIFile, ENCRYPTCODE, false); system("del TempSI.txt");
                                CurrentSIFile[0] = 0;

                                /* The following algorithm is used for NOT ACCEPTING purposes ONLY... */
                                // bool CheckForCurrentKD = false;
                                // strcpy(CurrentKDFile, "New_"UserCartStore_Keranjang);
                                // AccessCart = fopen(CurrentKDFile, "w");
                                // for (int Line = 1; Line <= CountBufferEOF("Temp_"UserCartStore_Keranjang); Line++) {
                                //     if (Line == 1) {
                                //         fprintf(AccessCart, "%d", atoi(ReadLine("Temp_"UserCartStore_Keranjang, Line)) - 1);
                                //     } else {
                                //         if (strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.FullName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.JobTitle) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.HeadRegion) != NULL) {
                                //             CheckForCurrentKD = true;
                                //             continue;
                                //         } else if (CheckForCurrentKD && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), SIFullName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), SIIndustryName) != NULL) {
                                //             continue;
                                //         } else if (CheckForCurrentKD && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductStock) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductPrice) != NULL) {
                                //             continue;
                                //         } else if (CheckForCurrentKD && atoi(ReadLine("Temp_"UserCartStore_Keranjang, Line)) == 0) {
                                //             CheckForCurrentKD = false;
                                //             continue;
                                //         } else {
                                //             fprintf(AccessCart, "%s", ReadLine("Temp_"UserCartStore_Keranjang, Line));
                                //         }
                                //     }
                                // } fclose(AccessCart); system("del Temp_"UserCartStore_Keranjang);
                                /* The following algorithm is used for NOT ACCEPTING purposes ONLY... */

                                char GetCurrentStock[BUFSIZE07] = { 0 }, SetCurrentStock[BUFSIZE07] = { 0 };
                                strcpy(GetCurrentStock, ReadLine("Temp_"Client_SektorIndustri, ((10 + 1) * SILoggedIn) + (8 + GetStockID)));
                                GetCurrentStock[strlen(GetCurrentStock) - 1] = '\0';
                                strcpy(ProductName, GetCurrentStock);
                                strtok_r(ProductName, ",", &ProductStock); ProductStock = TrimWhiteSpaces(ProductStock);
                                strtok_r(ProductStock, ",", &ProductPrice); ProductPrice = TrimWhiteSpaces(ProductPrice);
                                snprintf(SetCurrentStock, (sizeof(SetCurrentStock) * 3) + 13, "%s, %lld, %s", ProductName, atoll(ProductStock) - atoll(DisplayProductStock), ProductPrice);

                                OverWriteStringAtLine("Temp_"Client_SektorIndustri, SetCurrentStock, 0, ((10 + 1) * SILoggedIn) + (8 + GetStockID));
                        
                                EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
                                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
                                break;
                            }
                        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                        puts("");
                        puts(ANSI_COLOR_LIGHTGREEN"Status Pengajuan: PENGAJUAN DITERIMA");
                        puts(ANSI_COLOR_GREEN":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                        puts(ANSI_COLOR_GREEN":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!"ANSI_COLOR_RESET);
                        
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); CMMFeature03();

                    } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                        ClearScreen();
                        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
                        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
                        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
                        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

                        EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, true);
                        EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, true);
                        EncryptTextFile(UserCartStore_Keranjang, "Temp_"UserCartStore_Keranjang, -ENCRYPTCODE, true);
                        AvailableKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));
                        AvailableReqs = atoi(ReadLine("Temp_"UserCartStore_Keranjang, 1));

                        puts("");
                        puts("Berikut adalah data pengajuan kerja sama dari Kepala Daerah dengan yang bersangkutan...");
                        
                        puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
                        for (int KD = 0; KD < AvailableKDs; KD++) {
                            strcpy(KDList.FullName, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 3));
                            strcpy(KDList.JobTitle, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 8));
                            strcpy(KDList.HeadRegion, ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 9));
                            KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                            if (strstr(DisplayKDRequests[PeekKD - 1], KDList.FullName) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.JobTitle) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.HeadRegion) != NULL) {
                                printf(ANSI_COLOR_LIGHTWHITE"[%03d] Nama Lengkap: %s\n"ANSI_COLOR_RESET, PeekKD, KDList.FullName);
                                printf(ANSI_COLOR_LIGHTWHITE"... Jabatan/Daerah: %s %s\n"ANSI_COLOR_RESET, KDList.JobTitle, KDList.HeadRegion);

                                OverWriteStringAtLine("Temp_"User_KepalaDaerah, "-1", 0, ((10 + 1) * KD) + 12);
                                OverWriteStringAtLine("Temp_"UserCartStore_Keranjang, "-1", 0, ((4 + 1) * (PeekKD - 1)) + 6);

                                RecentStatus = atoi(ReadLine("Temp_"User_KepalaDaerah, ((10 + 1) * KD) + 12));
                                if      (RecentStatus == 0)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: -"ANSI_COLOR_RESET); }
                                else if (RecentStatus == 1)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTYELLOW"SEDANG DIPROSES"ANSI_COLOR_RESET); }
                                else if (RecentStatus == 2)  { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTGREEN"PENGAJUAN DITERIMA"ANSI_COLOR_RESET); }
                                else if (RecentStatus == -1) { puts(ANSI_COLOR_LIGHTWHITE"... Status Permintaan: " ANSI_COLOR_LIGHTRED"PENGAJUAN DITOLAK"ANSI_COLOR_RESET); }

                                strcpy(DisplayProductName, ReadLine("Temp_"UserCartStore_Keranjang, ((4 + 1) * (PeekKD - 1)) + 5));
                                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                                
                                puts("");
                                printf(ANSI_COLOR_LIGHTWHITE"Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

                                // bool CheckForCurrentKD = false;
                                // strcpy(CurrentKDFile, "New_"UserCartStore_Keranjang);
                                // AccessCart = fopen(CurrentKDFile, "w");
                                // for (int Line = 1; Line <= CountBufferEOF("Temp_"UserCartStore_Keranjang); Line++) {
                                //     if (Line == 1) {
                                //         fprintf(AccessCart, "%d\n", atoi(ReadLine("Temp_"UserCartStore_Keranjang, Line)) - 1);
                                //     } else if (!CheckForCurrentKD && Line == ((4 + 1) * AvailableReqs) + 2) {
                                //         CheckForCurrentKD = false;
                                //         fprintf(AccessCart, "\n");
                                //     }
                                    
                                //     if (CheckForCurrentKD) { CheckForCurrentKD = false; }
                                //     if (Line != 1 && Line != ((4 + 1) * AvailableReqs) + 2) {
                                //         if (strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.FullName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.JobTitle) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), KDList.HeadRegion) != NULL) {
                                //             CheckForCurrentKD = true;
                                //             continue;
                                //         } else if (CheckForCurrentKD && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), SIFullName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), SIIndustryName) != NULL) {
                                //             continue;
                                //         } else if (CheckForCurrentKD && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductName) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductStock) != NULL && strstr(ReadLine("Temp_"UserCartStore_Keranjang, Line), DisplayProductPrice) != NULL) {
                                //             continue;
                                //         } else if (CheckForCurrentKD && atoi(ReadLine("Temp_"UserCartStore_Keranjang, Line)) == 0) {
                                //             continue;
                                //         } else if (!CheckForCurrentKD) {
                                //             fprintf(AccessCart, "%s", ReadLine("Temp_"UserCartStore_Keranjang, Line));
                                //         }
                                //     }
                                // } fclose(AccessCart);

                                EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                                EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
                                EncryptTextFile("Temp_"UserCartStore_Keranjang, UserCartStore_Keranjang, ENCRYPTCODE, true);
                                break;
                            }
                        } puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

                        puts("");
                        puts(ANSI_COLOR_LIGHTRED"Status Pengajuan: PENGAJUAN DITOLAK");
                        puts(ANSI_COLOR_RED":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan");
                        puts(ANSI_COLOR_RED":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!"ANSI_COLOR_RESET);
                        
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); CMMFeature03();
                    
                    } else if (UpdateStatus == 'Q' || UpdateStatus == 'q') {
                        puts("");
                        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                        system("pause"); CMMFeature03();
                    }
                }

            } else if (PeekKD == 0) {
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                ClientMainMenu();

            } else { CheckInvalidInput = true; CMMFeature03(); }
        
        } else {
            puts("");
            puts(ANSI_COLOR_LIGHTYELLOW"Saat ini belum ada Kepala Daerah yang ingin mengajukan pemesanan produk kerja sama dengan pihak Anda...");
            puts(ANSI_COLOR_YELLOW"... Anda dapat menunggu dan/atau memantau secara berkala apakah ada pemesanan yang dilakukan ke depannya!");
            puts(ANSI_COLOR_CYAN"... Dipersilakan untuk kembali ke menu semula..."ANSI_COLOR_RESET);
            puts("");
            puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
            system("pause"); ClientMainMenu();
        }

    } else if (OCManaging == 2 && SIStandaloneStatus == 0) {
        ClearScreen();

        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda tengah masuk sebagai: " BRIGHTPINK219 ANSI_STYLE_BOLD"Client :: Sektor Industri."ANSI_COLOR_RESET);
        printf(BRIGHTPURPLE218 ANSI_STYLE_ITALIC"... Profil Sektor Industri: " ANSI_STYLE_UNDERLINE"%s, %s.\n"ANSI_COLOR_RESET, SIFullName, SIIndustryName);
        puts(BRIGHTPINK219"\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah"ANSI_COLOR_RESET);

        puts("");
        printf(ANSI_COLOR_MAGENTA"Saat ini STATUS pengajuan kerja sama/distribusi terbuka Anda: ");
        if (SIStandaloneStatus == 0)      { puts(ANSI_COLOR_LIGHTRED"TERTUTUP"ANSI_COLOR_RESET);  }
        else if (SIStandaloneStatus == 1) { puts(ANSI_COLOR_LIGHTGREEN"TERBUKA"ANSI_COLOR_RESET); }

        puts("");
        puts(ANSI_COLOR_LIGHTMAGENTA"Sekedar informasi, bahwa Anda tidak dapat mengelola pengajuan-pengajuan yang disampaikan oleh pelbagai");
        puts("pihak Kepala Daerah jika status penerimaan pengajuan Anda saat ini sedang TIDAK AKTIF!");
        puts(ANSI_COLOR_GREEN"... Silakan untuk DIBUKA terlebih dahulu akses pengajuannya agar Anda dapat mengelola lebih lenjut..."ANSI_COLOR_RESET);
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); CMMFeature03();

    } else if (OCManaging == 0) {
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); ClientMainMenu();
    } else { CheckInvalidInput = true; CMMFeature03(); }
}

void AdminLobbyMenu(void) {
    ClearScreen();

    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Nama pengguna dan/atau kata sandi salah!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk diperiksa kembali (tanpa batas pengecekan)!"ANSI_COLOR_RESET);
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; AdminLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"Admin :: Kementerian Keuangan."ANSI_COLOR_RESET);

    puts("");
    puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
    puts("... 1. Nama Pengguna (maks. 128 karakter)");
    puts("... 2. Kata Sandi    (8-16 karakter)");

    puts("");
    AcceptInputText("Nama Pengguna: ", AdminSignIn.SignInUsername)
    AcceptInputText("Kata Sandi:    ", AdminSignIn.SignInPassword)

    EncryptTextFile(Admin_Kemenkeu, "Temp_"Admin_Kemenkeu, -ENCRYPTCODE, false);
    if (strcmp(AdminSignIn.SignInUsername, ReadLine("Temp_"Admin_Kemenkeu, 1)) == 0 && \
        strcmp(AdminSignIn.SignInPassword, ReadLine("Temp_"Admin_Kemenkeu, 2)) == 0) {
            
            EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);
            
            ClearScreen();
            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: ADMIN.");
            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
            puts(ANSI_COLOR_CYAN"    dalam 3"ANSI_COLOR_RESET);
            sleep(1);
            ClearScreen();
            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: ADMIN.");
            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
            puts(ANSI_COLOR_CYAN"    dalam 3, 2"ANSI_COLOR_RESET);
            sleep(1);
            ClearScreen();
            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: ADMIN.");
            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
            puts(ANSI_COLOR_CYAN"    dalam 3, 2, 1..."ANSI_COLOR_RESET);
            sleep(1);
            
            AdminMainMenu();
    
    } else {
        CheckInvalidInput = true;
        EncryptTextFile("Temp_"Admin_Kemenkeu, Admin_Kemenkeu, ENCRYPTCODE, true);
        AdminLobbyMenu();
    }
}

void UserLobbyMenu(void) {
    ClearScreen();

    int RegisteredKDs = 0;
    if (CheckInvalidInput) {
        if (RSOption == 0) {
            puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
            puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);
        } else if (RSOption == 2) {
            puts(ANSI_COLOR_LIGHTRED"ERROR: NIK dan/atau kata sandi salah!");
            puts(ANSI_COLOR_YELLOW"... Silahkan untuk diperiksa kembali (tidak ada batasan pengecekan)!"ANSI_COLOR_RESET);
        }
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; UserLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    if (RSOption == 0) {
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"User :: Kepala Daerah."ANSI_COLOR_RESET);

        puts("");
        puts("Anda dipersilakan untuk memilih satu dari dua opsi berikut ini... .");
        puts("[1] Registrasi  (Sign-up)");
        puts("[2] Masuk       (Sign-in/Login)");
        puts("[0] Kembali...");
        AcceptInputOption("> Pilihan Anda: ", RSOption);
    }

    if (RSOption < 0) {
        CheckInvalidInput = true;
        UserLobbyMenu();
    } else if (RSOption == 0) { HomeMenu(); }
    
    else {
        if (RSOption == 1) {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"User :: Kepala Daerah."ANSI_COLOR_RESET);

            puts("");
            puts("Silakan untuk memasukkan TUJUH (7) kredensial baru Anda seperti berikut:");
            if (CountRegists >= 2) printf(ANSI_COLOR_GREEN"... 1. Nama Lengkap:         %s\n"ANSI_COLOR_RESET, KDSignIn.FullName);
            if (CountRegists >= 3) printf(ANSI_COLOR_GREEN"... 2. NIK:                  %s\n"ANSI_COLOR_RESET, KDSignIn.NIK);
            if (CountRegists >= 4) printf(ANSI_COLOR_GREEN"... 3. E-mail:               %s\n"ANSI_COLOR_RESET, KDSignIn.Email);
            if (CountRegists >= 5) { printf(ANSI_COLOR_GREEN"... 4. Kata Sandi:           "); for (size_t i = 0; i < strlen(KDSignIn.Password); i++) { printf("*"); } printf("\n"ANSI_COLOR_RESET); }
            if (CountRegists >= 6) printf(ANSI_COLOR_GREEN"... 5. Tempat/Tanggal Lahir: %s\n"ANSI_COLOR_RESET, KDSignIn.BirthPlaceDate);
            if (CountRegists >= 7) printf(ANSI_COLOR_GREEN"... 6. Jabatan:              %s\n"ANSI_COLOR_RESET, KDSignIn.JobTitle);
            if (CountRegists >= 8) printf(ANSI_COLOR_GREEN"... 7. Daerah Perwakilan:    %s\n"ANSI_COLOR_RESET, KDSignIn.HeadRegion);
            if (CountRegists < 2)  printf(ANSI_COLOR_YELLOW"... 1. Nama Lengkap:         (maks. 128 karakter)\n"ANSI_COLOR_RESET);
            if (CountRegists < 3)  printf(ANSI_COLOR_YELLOW"... 2. NIK:                  (wajib 16 digit)\n"ANSI_COLOR_RESET);
            if (CountRegists < 4)  printf(ANSI_COLOR_YELLOW"... 3. E-mail:               (memenuhi sintaks e-mail sesungguhnya)\n"ANSI_COLOR_RESET);
            if (CountRegists < 5)  printf(ANSI_COLOR_YELLOW"... 4. Kata Sandi:           (8-16 karakter)\n"ANSI_COLOR_RESET);
            if (CountRegists < 6)  printf(ANSI_COLOR_YELLOW"... 5. Tempat/Tanggal Lahir: (format: TEMPAT, DD/MM/YYYY)\n"ANSI_COLOR_RESET);
            if (CountRegists < 7)  printf(ANSI_COLOR_YELLOW"... 6. Jabatan:              (golongan gubernur/bupati/wali kota)\n"ANSI_COLOR_RESET);
            if (CountRegists < 8)  printf(ANSI_COLOR_YELLOW"... 7. Daerah Perwakilan:    (nama daerah dari kepala daerah)\n"ANSI_COLOR_RESET);
            
            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Lengkap: ", KDSignIn.FullName);
                if (strlen(KDSignIn.FullName) < 2 || strlen(KDSignIn.FullName) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data nama lengkap melebihi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.FullName[strlen(KDSignIn.FullName) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("NIK: ", KDSignIn.NIK);
                if (strlen(KDSignIn.NIK) != 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data NIK belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.NIK[strlen(KDSignIn.NIK) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 3) {
                AcceptInputText("E-mail: ", KDSignIn.Email);
                if (strchr(KDSignIn.Email, '@') == NULL || strchr(KDSignIn.Email, '.') == NULL || strchr(KDSignIn.Email, ' ') != NULL || strlen(KDSignIn.Email) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data e-mail belum sesuai dengan sintaks yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.Email[strlen(KDSignIn.Email) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 4) {
                AcceptInputText("Kata Sandi: ", KDSignIn.Password);
                if (strlen(KDSignIn.Password) < 9 || strlen(KDSignIn.Password) > 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data kata sandi belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.Password[strlen(KDSignIn.Password) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 5) {
                AcceptInputText("Tempat/Tanggal Lahir: ", KDSignIn.BirthPlaceDate);
                if (strchr(KDSignIn.BirthPlaceDate, ',') == NULL || strchr(KDSignIn.BirthPlaceDate, ' ') == NULL || strlen(KDSignIn.BirthPlaceDate) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data tempat/tanggal lahir belum memenuhi kriteria yang diminta!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.BirthPlaceDate[strlen(KDSignIn.BirthPlaceDate) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 6) {
                AcceptInputText("Jabatan (Gubernur/Bupati/Wali Kota): ", KDSignIn.JobTitle);
                if (strcmp(StringCapitalize(KDSignIn.JobTitle), "Gubernur\n") != 0 && strcmp(StringCapitalize(KDSignIn.JobTitle), "Bupati\n") != 0 && strcmp(StringCapitalize(KDSignIn.JobTitle), "Wali kota\n") != 0) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data golongan jabatan belum sesuai dengan pilihan yang tersedia!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { 
                    if (strcmp(StringCapitalize(KDSignIn.JobTitle), "Wali kota\n") == 0) { strcpy(KDSignIn.JobTitle, "Wali Kota\n"); }
                    CountRegists++; KDSignIn.JobTitle[strlen(KDSignIn.JobTitle) - 1] = '\0'; UserLobbyMenu();
                }
            
            } if (CountRegists == 7) {
                AcceptInputText("Kepala Wilayah/Daerah: ", KDSignIn.HeadRegion);
                if (strlen(KDSignIn.HeadRegion) < 2 || strlen(KDSignIn.HeadRegion) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data kepala wilayah/daerah terlalu singkat/panjang!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.HeadRegion[strlen(KDSignIn.HeadRegion) - 1] = '\0'; UserLobbyMenu(); }    
            }

            if (CountRegists == 8) {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Kepala daerah baru telah berhasil didaftarkan!");
                puts(ANSI_COLOR_MAGENTA"INFO: Silakan untuk melanjutkan interaksi berikut dengan masuk ke menu sign-in/login... ."ANSI_COLOR_RESET);
                
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");

                WritePublicKepalaDaerah(false);

                CountRegists = 1; RSOption = 2;
                KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                UserLobbyMenu();
            }

        } else if (RSOption == 2) {
            if (access(User_KepalaDaerah, F_OK) != 0) {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTRED"ERROR: Belum terdapat kepala daerah yang terdaftarkan!");
                puts(ANSI_COLOR_YELLOW"... Silahkan untuk masuk ke menu registrasi kepala daerah terlebih dahulu!"ANSI_COLOR_RESET);

                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                
                CountRegists = 1; RSOption = 1;
                KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                UserLobbyMenu();
            }

            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"User :: Kepala Daerah."ANSI_COLOR_RESET);

            puts("");
            puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
            if (CountRegists >= 2) printf(ANSI_COLOR_GREEN"... 1. NIK:        %s\n"ANSI_COLOR_RESET, KDSignIn.NIK);
            if (CountRegists >= 3) { printf(ANSI_COLOR_GREEN"... 2. Kata Sandi: "); for (size_t i = 0; i < strlen(KDSignIn.Password); i++) { printf("*"); } printf("\n"ANSI_COLOR_RESET); }
            if (CountRegists < 2)  printf(ANSI_COLOR_YELLOW"... 1. NIK:        (wajib 16 digit)\n"ANSI_COLOR_RESET);
            if (CountRegists < 3)  printf(ANSI_COLOR_YELLOW"... 2. Kata Sandi: (8-16 karakter)\n"ANSI_COLOR_RESET);

            puts("");
            if (CountRegists == 1) {
                AcceptInputText("NIK: ", KD_SignInNIK);
                if (strlen(KD_SignInNIK) != 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data NIK belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; strncpy(KDSignIn.NIK, KD_SignInNIK, 32); KDSignIn.NIK[strlen(KDSignIn.NIK) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Kata Sandi: ", KD_SignInPassword);
                if (strlen(KD_SignInPassword) < 9 || strlen(KD_SignInPassword) > 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data kata sandi belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; strncpy(KDSignIn.Password, KD_SignInPassword, 32); KDSignIn.Password[strlen(KDSignIn.Password) - 1] = '\0'; UserLobbyMenu(); }
            }

            if (CountRegists == 3) {
                EncryptTextFile(User_KepalaDaerah, "Temp_"User_KepalaDaerah, -ENCRYPTCODE, false);
                RegisteredKDs = atoi(ReadLine("Temp_"User_KepalaDaerah, 1));

                for (int KD = 0; KD < RegisteredKDs; KD++) {
                    if (strcmp(KD_SignInNIK, ReadLine("Temp_"User_KepalaDaerah, (((10 + 1) * KD) + 4))) == 0 && \
                        strcmp(KD_SignInPassword, ReadLine("Temp_"User_KepalaDaerah, (((10 + 1) * KD) + 6))) == 0) {

                            strncpy(KDFullName, ReadLine("Temp_"User_KepalaDaerah, (((10 + 1) * KD) + 3)), BUFSIZE07);
                            strncpy(KDJobTitle, ReadLine("Temp_"User_KepalaDaerah, (((10 + 1) * KD) + 8)), BUFSIZE07);
                            strncpy(KDHeadRegion, ReadLine("Temp_"User_KepalaDaerah, (((10 + 1) * KD) + 9)), BUFSIZE07);
                            KDFullName[strlen(KDFullName) - 1] = '\0'; KDJobTitle[strlen(KDJobTitle) - 1] = '\0'; KDHeadRegion[strlen(KDHeadRegion) - 1] = '\0';

                            SuccessfullyLoggedIn = true; KDLoggedIn = KD;
                            EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: USER.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3"ANSI_COLOR_RESET);
                            sleep(1);
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: USER.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3, 2"ANSI_COLOR_RESET);
                            sleep(1);
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: USER.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3, 2, 1..."ANSI_COLOR_RESET);
                            sleep(1);
                            
                            CountRegists = 1; RSOption = 3; // Just to be sure to avoid the infinite loop after first-time registration.
                            KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                            KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                    }
                }

                if (!SuccessfullyLoggedIn) {
                    CheckInvalidInput = true;
                    CountRegists = 1; RSOption = 2;
                    KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                    KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                    EncryptTextFile("Temp_"User_KepalaDaerah, User_KepalaDaerah, ENCRYPTCODE, true);
                    UserLobbyMenu();
                
                } else { UserMainMenu(); }
            }
        
        } else if (RSOption == 3) { NULL; }
        
        else {
            CheckInvalidInput = true;
            UserLobbyMenu();
        }
    }
}

void ClientLobbyMenu(void) {
    ClearScreen();

    int RegisteredSIs = 0;
    if (CheckInvalidInput) {
        if (RSOption == 0) {
            puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
            puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);
        } else if (RSOption == 2) {
            puts(ANSI_COLOR_LIGHTRED"ERROR: Nama pengguna dan/atau kata sandi salah!");
            puts(ANSI_COLOR_YELLOW"... Silahkan untuk diperiksa kembali (tidak ada batasan pengecekan)!"ANSI_COLOR_RESET);
        }
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; ClientLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    if (RSOption == 0) {
        puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
        puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"Client :: Sektor Industri."ANSI_COLOR_RESET);

        puts("");
        puts("Anda dipersilakan untuk memilih satu dari dua opsi berikut ini... .");
        puts("[1] Registrasi  (Sign-up)");
        puts("[2] Masuk       (Sign-in/Login)");
        puts("[0] Kembali...");
        AcceptInputOption("> Pilihan Anda: ", RSOption);
    }

    if (RSOption < 0) {
        CheckInvalidInput = true;
        ClientLobbyMenu();
    } else if (RSOption == 0) { HomeMenu(); }
    
    else {
        if (RSOption == 1) {
            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"Client :: Sektor Industri."ANSI_COLOR_RESET);

            puts("");
            puts("Silakan untuk memasukkan EMPAT (4) kredensial baru Anda seperti berikut:");
            if (CountRegists >= 2) printf(ANSI_COLOR_GREEN"... 1. Nama Lengkap:  %s\n"ANSI_COLOR_RESET, SISignIn.FullName);
            if (CountRegists >= 3) printf(ANSI_COLOR_GREEN"... 2. Nama Industri: %s\n"ANSI_COLOR_RESET, SISignIn.IndustryName);
            if (CountRegists >= 4) printf(ANSI_COLOR_GREEN"... 3. Nama Pengguna: %s\n"ANSI_COLOR_RESET, SISignIn.Username);
            if (CountRegists >= 5) { printf(ANSI_COLOR_GREEN"... 4. Kata Sandi:  "); for (size_t i = 0; i < strlen(SISignIn.Password); i++) { printf("*"); } printf("\n"ANSI_COLOR_RESET); }
            if (CountRegists < 2)  printf(ANSI_COLOR_YELLOW"... 1. Nama Lengkap:  (maks. 128 karakter)\n"ANSI_COLOR_RESET);
            if (CountRegists < 3)  printf(ANSI_COLOR_YELLOW"... 2. Nama Industri: (maks. 128 karakter)\n"ANSI_COLOR_RESET);
            if (CountRegists < 4)  printf(ANSI_COLOR_YELLOW"... 3. Nama Pengguna: (maks. 128 karakter)\n"ANSI_COLOR_RESET);
            if (CountRegists < 5)  printf(ANSI_COLOR_YELLOW"... 4. Kata Sandi:    (8-16 karakter)\n"ANSI_COLOR_RESET);
            
            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Lengkap: ", SISignIn.FullName);
                if (strlen(SISignIn.FullName) < 2 || strlen(SISignIn.FullName) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data nama lengkap melebihi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.FullName[strlen(SISignIn.FullName) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Nama Industri: ", SISignIn.IndustryName);
                if (strlen(SISignIn.IndustryName) < 2 || strlen(SISignIn.IndustryName) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data nama industri melebihi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.IndustryName[strlen(SISignIn.IndustryName) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 3) {
                AcceptInputText("Nama Pengguna: ", SISignIn.Username);
                if (strlen(SISignIn.Username) < 2 || strlen(SISignIn.Username) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data nama pengguna melebihi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.Username[strlen(SISignIn.Username) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 4) {
                AcceptInputText("Kata Sandi: ", SISignIn.Password);
                if (strlen(SISignIn.Password) < 9 || strlen(SISignIn.Password) > 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data kata sandi belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.Password[strlen(SISignIn.Password) - 1] = '\0'; ClientLobbyMenu(); }
            
            }

            if (CountRegists == 5) {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Sektor industri baru telah berhasil didaftarkan!");
                puts(ANSI_COLOR_MAGENTA"INFO: Silakan untuk melanjutkan interaksi berikut dengan masuk ke menu sign-in/login... ."ANSI_COLOR_RESET);
                
                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");

                WritePublicSektorIndustri(false);

                CountRegists = 1; RSOption = 2;
                SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                ClientLobbyMenu();
            }

        } else if (RSOption == 2) {
            if (access(Client_SektorIndustri, F_OK) != 0) {
                ClearScreen();

                puts(ANSI_COLOR_LIGHTRED"ERROR: Belum terdapat sektor industri yang terdaftarkan!");
                puts(ANSI_COLOR_YELLOW"... Silahkan untuk masuk ke menu registrasi sektor industri terlebih dahulu!"ANSI_COLOR_RESET);

                puts("");
                puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                system("pause");
                
                CountRegists = 1; RSOption = 1;
                SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                ClientLobbyMenu();
            }

            ClearScreen();

            puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
            puts(ANSI_COLOR_BLUE"Anda berada dalam lobi: " BRIGHTGREEN156"Client :: Sektor Industri."ANSI_COLOR_RESET);

            puts("");
            puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
            if (CountRegists >= 2) printf(ANSI_COLOR_GREEN"... 1. Nama Pengguna: %s\n"ANSI_COLOR_RESET, SISignIn.Username);
            if (CountRegists >= 3) { printf(ANSI_COLOR_GREEN"... 2. Kata Sandi:    "); for (size_t i = 0; i < strlen(SISignIn.Password); i++) { printf("*"); } printf("\n"ANSI_COLOR_RESET); }
            if (CountRegists < 2)  printf(ANSI_COLOR_YELLOW"... 1. Nama Pengguna: (wajib 16 digit)\n"ANSI_COLOR_RESET);
            if (CountRegists < 3)  printf(ANSI_COLOR_YELLOW"... 2. Kata Sandi:    (8-16 karakter)\n"ANSI_COLOR_RESET);

            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Pengguna: ", SI_SignInUsername);
                if (strlen(SI_SignInUsername) < 2 || strlen(SI_SignInUsername) > 128) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data nama pengguna melebihi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; strncpy(SISignIn.Username, SI_SignInUsername, BUFSIZE07); SISignIn.Username[strlen(SISignIn.Username) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Kata Sandi: ", SI_SignInPassword);
                if (strlen(SI_SignInPassword) < 9 || strlen(SI_SignInPassword) > 17) {
                    puts("");
                    puts(ANSI_COLOR_LIGHTRED"ERROR: Data kata sandi belum memenuhi batas yang ditentukan!"ANSI_COLOR_RESET);
                    puts("");
                    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; strncpy(SISignIn.Password, SI_SignInPassword, 32); SISignIn.Password[strlen(SISignIn.Password) - 1] = '\0'; ClientLobbyMenu(); }
            }

            if (CountRegists == 3) {
                EncryptTextFile(Client_SektorIndustri, "Temp_"Client_SektorIndustri, -ENCRYPTCODE, false);
                RegisteredSIs = atoi(ReadLine("Temp_"Client_SektorIndustri, 1));

                for (int SI = 0; SI < RegisteredSIs; SI++) {
                    if (strcmp(SI_SignInUsername, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SI) + 5))) == 0 && \
                        strcmp(SI_SignInPassword, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SI) + 6))) == 0) {

                            strncpy(SIFullName, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SI) + 3)), BUFSIZE07);
                            strncpy(SIIndustryName, ReadLine("Temp_"Client_SektorIndustri, (((10 + 1) * SI) + 4)), BUFSIZE07);
                            SIFullName[strlen(SIFullName) - 1] = '\0'; SIIndustryName[strlen(SIIndustryName) - 1] = '\0';

                            SuccessfullyLoggedIn = true; SILoggedIn = SI;
                            EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
                
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: CLIENT.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3"ANSI_COLOR_RESET);
                            sleep(1);
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: CLIENT.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3, 2"ANSI_COLOR_RESET);
                            sleep(1);
                            ClearScreen();
                            puts(ANSI_COLOR_LIGHTGREEN"SUCCESS: Anda berhasil masuk dengan status: CLIENT.");
                            puts(ANSI_COLOR_CYAN"... Dimohon untuk dilanjutkan dengan interaksi berikut..."ANSI_COLOR_RESET);
                            puts(ANSI_COLOR_CYAN"    dalam 3, 2, 1..."ANSI_COLOR_RESET);
                            sleep(1);
                            
                            CountRegists = 1; RSOption = 3; // Just to be sure to avoid the infinite loop after first-time registration.
                            SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                    }
                }

                if (!SuccessfullyLoggedIn) {
                    CheckInvalidInput = true;
                    CountRegists = 1; RSOption = 2;
                    SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                    EncryptTextFile("Temp_"Client_SektorIndustri, Client_SektorIndustri, ENCRYPTCODE, true);
                    ClientLobbyMenu();
                
                } else { ClientMainMenu(); }
            }
        
        } else if (RSOption == 3) { NULL; }
        
        else {
            CheckInvalidInput = true;
            ClientLobbyMenu();
        }
    }
}

void AboutDWakandaPage(void) {
    ClearScreen();
    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!"ANSI_COLOR_RESET);
    puts(ANSI_COLOR_LIGHTBLUE"Anda berada dalam menu: Home Menu :: Tentang D'Wakanda");

    puts("");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"D'Wakanda merupakan program yang mensimulasikan keuangan sebuah negara, di mana pengguna berperan\nsebagai Kemenkeu, Kepada Daerah, dan Sektor Industri yang dapat mengelola berbagai aspek kebijakan\nfiskal, seperti pajak negara, pengeluaran dan pendapatan daerah, dana bantuan, hingga kerja sama\ndengan sektor industri, pemerintah pusat, dan daerah lainnya.\n");
    puts(BRIGHTBLUE159"Untuk Admin, yang berperan sebagai Kementerian Keuangan, memiliki menu sign in yang memungkinkan\nmereka masuk tanpa perlu mendaftar, menggunakan nama pengguna dan kata sandi yang ditetapkan. Pada\nMenu Utama, Kemenkeu dapat mengatur pajak negara untuk untuk mendukung proses investasi yang\ndilakukan oleh kepala  daerah, yang keuntungannya akan disimpan dalam Tabungan Negara. Selain itu,\nKemenkeu dapat melihat total tabungan negara yang berasal dari pendapatan hasil investasi, memantau\nseluruh pendapatan dari daerah, dan melihat data tentang tugas yang diberikan ke masing-masing\nkepala wilayah. Selain itu, Admin juga dapat mengakses data sektor industri, mengatur\npendistribusian dana, dan distribusi perdagangan internasional.\n");
    puts(BRIGHTPURPLE218"Untuk Pengguna/User, yakni Kepala Daerah, terdapat fitur registrasi yang memerlukan informasi\nseperti nama lengkap, NIK, e-mail, kata sandi, tempat/tanggal lahir, jabatan, dan daerah\nperwakilan. Setelah terdaftar, Kepala Daerah dapat login menggunakan NIK dan kata sandi. Di Menu\nUtama, Kepala Daerah dapat melihat alur data perekonomian dana daerah, mengajukan bantuan dana\nkepada pemerintah pusat, dan mengatur pendistribusian dari dana tersebut. Pengguna juga dapat\nmengatur kerja sama dengan sektor industri yang memiliki nilai tambah.\n");
    puts(BRIGHTMAGENTA211"Untuk Klien/Client, yakni Sektor Industri, terdapat fitur registrasi yang memerlukan informasi nama\nlengkap, nama pengguna, dan nama sektor industri. Diperlukan nama pengguna dan kata sandi untuk\nmelakukan login. Sektor Industri dapat melihat pendapatan dari hasil produksi industri, mengatur\nproduksi dari industri, dan mengatur kerja sama dengan kepala daerah.");
    puts(ANSI_COLOR_LIGHTWHITE"===================================================================================================="ANSI_COLOR_RESET);

    puts("");
    puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
    system("pause"); HomeMenu();
}

void HomeMenu(void) {
    ClearScreen();

    int AUCOption = 0; RSOption = 0;
    if (CheckInvalidInput) {
        puts(ANSI_COLOR_LIGHTRED"ERROR: Input yang diterima tidaklah valid!");
        puts(ANSI_COLOR_YELLOW"... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!"ANSI_COLOR_RESET);
        CheckInvalidInput = false;
        
        puts("");
        puts(ANSI_COLOR_MAGENTA ANSI_STYLE_ITALIC"(tekan tombol [ENTER] untuk melanjutkan...)"ANSI_COLOR_RESET);
        system("pause"); HomeMenu();
    }

    puts(ANSI_COLOR_LIGHTMAGENTA"Selamat Datang di aplikasi: D'Wakanda!");
    puts(ANSI_COLOR_LIGHTBLUE"Anda berada dalam menu: Home Menu"ANSI_COLOR_RESET);

    puts("");
    puts(ANSI_COLOR_LIGHTWHITE"::    Anda dipersilakan untuk memilih SATU dari TIGA opsi berikut ini!    ::");
    puts(ANSI_COLOR_WHITE"::  Pastikan Anda ingin masuk sebagai siapa, dan pahamilah peran beliau!  ::");
    puts(ANSI_COLOR_WHITE":: Deskripsi dan peran tugas dapat Anda baca pada menu: Tentang D'Wakanda ::");

    puts("");
    puts(BRIGHTGREEN156"[1] Admin  :: Kementerian Keuangan");
    puts(BRIGHTBLUE159"[2] User   :: Kepala Daerah");
    puts(BRIGHTPURPLE218"[3] Client :: Sektor Industri");

    puts("");
    puts(BRIGHTMAGENTA211"[9] Tentang D'Wakanda"ANSI_COLOR_RESET);
    AcceptInputOption("> Pilihan Anda: ", AUCOption);

    if (AUCOption <= 0) {
        CheckInvalidInput = true;
        HomeMenu();
    } else {
        CheckInvalidInput = false;

        switch (AUCOption) {
            case 1:  { AdminLobbyMenu();                     } break;
            case 2:  { UserLobbyMenu();                      } break;
            case 3:  { ClientLobbyMenu();                    } break;
            case 9:  { AboutDWakandaPage();                  } break;
            default: { CheckInvalidInput = true; HomeMenu(); } break;
        }
    }
}

int main(void) {
#if 1
    /* NOTE: Always do this at the starting point... */
    fflush(stdout); fflush(stdin);
    setlocale(LC_NUMERIC, "");               //// NOTE: Formatting thousands with comma!

    WritePrivateKemenkeu(false);
    WritePrivateKeranjang(true, 1, false);   //// NOTE: Do this only ONCE if the file are not EXIST yet!
    WritePrivateKeranjang(false, 1, false);  //// NOTE: Do this only ONCE if the file are not EXIST yet!
    HomeMenu();

    return 0;
}
#else
    // EncryptTextFile("contoh.txt", "contoh_hasil_enkripsi.txt", 255780, true);
    // DecryptTextFile("contoh_hasil_enkripsi.txt", true, 255780, NULL);

    // DecryptTextFile("Kemenkeu.txt", true, ENCRYPTCODE, NULL); puts("");
    // DecryptTextFile("KepalaDaerah.txt", true, ENCRYPTCODE, NULL); puts("");
    // DecryptTextFile("SektorIndustri.txt", true, ENCRYPTCODE, NULL); puts("");

    EncryptTextFile("e.txt", AdminCartStore_Keranjang, ENCRYPTCODE, false);
    // EncryptTextFile("b.txt", "KD - Stevannie.txt", ENCRYPTCODE, false);
    // EncryptTextFile("c.txt", User_KepalaDaerah, ENCRYPTCODE, false);
    // EncryptTextFile("nnn copy.txt", "KD - Nue copy.txt", ENCRYPTCODE, false);
    // EncryptTextFile("KeranjangKemenkeu.txt", "a.txt", -ENCRYPTCODE, false);
    // DecryptTextFile("KepalaDaerah.txt", true, ENCRYPTCODE, NULL);
    // DecryptTextFile("Temp_"UserCartStore_Keranjang, true, ENCRYPTCODE, NULL);
    // DecryptTextFile("KeranjangKepalaDaerah.txt", true, ENCRYPTCODE, NULL);
    // DecryptTextFile("KeranjangKemenkeu.txt", true, ENCRYPTCODE, NULL);
    // DecryptTextFile("KD - Nue.txt", true, ENCRYPTCODE, NULL);
    // DecryptTextFile("KD - Stevannie.txt", true, ENCRYPTCODE, NULL);
    // DecryptTextFile("SektorIndustri.txt", true, ENCRYPTCODE, NULL);

    // printf("%d\n", CountBufferEOF("contoh_hasil_enkripsi.txt"));

    return 0;
}
#endif
