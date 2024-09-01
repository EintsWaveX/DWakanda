#include <ctype.h>              // Characters typing methods
#include <dirent.h>             // Working with directories and files
#include <locale.h>             // Limitations per data types
#include <math.h>               // Mathematical functions
#include <stdbool.h>            // Standard boolean values handling
#include <stdint.h>             // Standard integers handling (more spesific)
#include <stdio.h>              // Standard stream handling
#include <stdlib.h>             // Standard library (more spesific)
#include <string.h>             // String manipulation and handling

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

/*
DEFINE::FILENAMES
Usage:  Used to only be a constant file namings.
*/
#define Admin_Kemenkeu             "Kemenkeu.txt"
#define User_KepalaDaerah          "KepalaDaerah.txt"
#define Client_SektorIndustri      "SektorIndustri.txt"
#define AdminCartStore_Keranjang   "KeranjangKemenkeu.txt"
#define UserCartStore_Keranjang    "KeranjangKepalaDaerah.txt"

/*
DEFINE::CONSTANT_DATA_FILE_IDS
Usage:  Used to identified each files data per LINE accordingly.
*/
#define AVAILABLE_DATA 1

// <-------------------------------------------------->
// Global constants for: ADMIN - Ministry of Finance
// OFFSET: 0
// <-------------------------------------------------->
#define MF_USERNAME                     1
#define MF_PASSWORD                     2
#define MF_STATE_TAXES                  3
#define MF_STATE_SAVINGS                4
#define __MF_OPEN_STATUS                5 // NOTE: UNUSED!

// <-------------------------------------------------->
// Global constants for: USER - Head District
// OFFSET: 3 (-2 for the AVAILABLE_DATA and NEW_LINE)
// <-------------------------------------------------->
#define OFFSET_HD                       10
#define HD_FULLNAME                     3
#define HD_CIN                          4
#define HD_EMAIL                        5
#define HD_PASSWORD                     6
#define HD_BIRTH_DATE                   7
#define HD_DEPARTMENT                   8
#define HD_DISTRICT_NAME                9
#define HD_AID_FUNDS_STATUS             10
#define __HD_UNUSED_STATUS_ID           11 // NOTE: UNUSED!
#define HD_SI_BOUGHT_PRODUCT_STATUS     12

// <-------------------------------------------------->
// Global constants for: CLIENT - Sector Industry
// OFFSET: 3 (-2 for the AVAILABLE_DATA and NEW_LINE)
// <-------------------------------------------------->
#define OFFSET_SI                       10
#define SI_FULLNAME                     3
#define SI_INDUSTRY_NAME                4
#define SI_USERNAME                     5
#define SI_PASSWORD                     6
#define __SI_OPEN_STATUS                7 // NOTE: UNUSED!
#define SI_PRODUCT_NO_1                 8
#define SI_PRODUCT_NO_2                 9
#define SI_PRODUCT_NO_3                 10
#define SI_PRODUCT_NO_4                 11
#define SI_PRODUCT_NO_5                 12

// <-------------------------------------------------->
// Global constants for: Cart Shopping History
// APPLIED TO:
//         ... 1. ADMIN - Ministry of Finance
//         ... 2. USER  - Head District
// OFFSET: 3 (-2 for the AVAILABLE_DATA and NEW_LINE)
// <-------------------------------------------------->
#define OFFSET_CS                       4
#define CS_HD_IDENTITY                  3
#define CS_CS_IDENTITY                  4
#define CS_BOUGHT_PRODUCT               5
#define CS_SELLING_STATUS               6

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

void SearchAll(const char*, bool, int, const char*);
void OverWriteStringAtLine(const char*, const char*, const int, intmax_t);
int  FindOccurences(const char*, char);
int  CountFDBuffer(const char*);
char *TrimWhiteSpaces(char*);
char *StringUppercase(char*);
char *StringLowercase(char*);
char *StringCapitalize(char*);
char *StringCapitalizeAll(char*);
char *ReadLine(const char*, intmax_t);

void HomeMenu(void);
void AboutDWakandaPage(void);
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

void SearchAll(const char* DestinationTextFile, bool ReadDecryptedFile, int DecryptionKey, const char* ReadByFileNameAndKeys) {
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

char *StringCapitalizeAll(char* SourceString) {
    bool CheckCap = false;

    for (int i = 0; SourceString[i] != '\0'; i++) {
        if (SourceString[i] == ' ') CheckCap = false;
        if (SourceString[0] >= 'A' && SourceString[0] <= 'Z') NULL;
        if (SourceString[0] >= 'a' && SourceString[0] <= 'z') { SourceString[0] -= 32; CheckCap = true; }
        if (i != 0 && !CheckCap && (SourceString[i] >= 'A' && SourceString[i] <= 'Z')) { SourceString[i] += 32; CheckCap = true; }
        if (i != 0 && !CheckCap && (SourceString[i] >= 'a' && SourceString[i] <= 'z')) { SourceString[i] -= 32; CheckCap = true; }
    } return SourceString;
}

int FindOccurences(const char* SourceString, char SearchedOccurence) {
    int CountOccurences;
    for (int i = 0; (long long unsigned int)i < strlen(SourceString) - 1; i++) {
        if (SourceString[i] == SearchedOccurence) CountOccurences++;
    } return CountOccurences;
}

int CountFDBuffer(const char* SourceString) {
    FILE *FSource = fopen(SourceString, "r");
    int Lines = 0;
    
    while((fscanf(FSource, "%*[^\n]"), fscanf(FSource, "%*c")) != EOF) { Lines++; }
    Lines++; fclose(FSource); return Lines;
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
    char ProductAd[BUFSIZE10];
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
#define MAX_ADMIN_SAVINGS 1000000000000000LL
void WritePrivateKemenkeu() {
    Kemenkeu KepalaWakanda = {
                                .Username = "D'Wakanda",
                                .Password = "Kemenkeu2024",
                                .StateTaxes = "00,00",
                                .StateSavings = "1000000000000000",
                                .Status = 1 // NOTE: UNUSED!
                            };
    
    if (access(Admin_Kemenkeu, F_OK) != 0) {
        Admin = fopen(Admin_Kemenkeu, "w");

        if (Admin == NULL) {
            fprintf(stderr, "ERROR: Tidak dapat menuliskan data admin Kemenkeu ke dalam file.\n");
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            HomeMenu();
        }

        fprintf(Admin, "%s\n%s\n%s\n%s\n//// %d :: UNUSED\n", KepalaWakanda.Username, KepalaWakanda.Password, KepalaWakanda.StateTaxes, KepalaWakanda.StateSavings, KepalaWakanda.Status);        
        fclose(Admin);
    }
}

KepalaDaerah KDSignIn = { 0 };
char KD_SignInNIK[32] = { 0 }, KD_SignInPassword[32] = { 0 };
char KDFullName[BUFSIZE07] = { 0 }, KDJobTitle[BUFSIZE07] = { 0 }, KDHeadRegion[BUFSIZE07] = { 0 };
int KDLoggedIn = 0;
#define MAX_USER_SAVINGS 1000000000000LL
void WritePublicKepalaDaerah(void) {
    int RegisteredKDs = 0;
    char WrittenRegisteredKDs[BUFSIZE07], CreateKDSavings[BUFSIZE07];

    if (access(User_KepalaDaerah, F_OK) != 0) {
        User = fopen(User_KepalaDaerah, "w");

        if (User == NULL) {
            fprintf(stderr, "ERROR: Tidak dapat menuliskan data pengguna Kepala Daerah ke dalam file.\n");
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        fprintf(User, "0\n//// 0 :: UNUSED!\n0\n"); // 0 [1]: Admin fundraising status, 0 [2]: UNUSED, 0 [3]: Client approval status.
        
        fclose(User);

    } else {
        RegisteredKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
        RegisteredKDs++;
        snprintf(WrittenRegisteredKDs, sizeof(WrittenRegisteredKDs), "%d", RegisteredKDs);
        OverWriteStringAtLine(User_KepalaDaerah, WrittenRegisteredKDs, 0, AVAILABLE_DATA);

        User = fopen(User_KepalaDaerah, "a");
        fprintf(User, "\n");
        fprintf(User, "%s\n", KDSignIn.FullName);
        fprintf(User, "%s\n", KDSignIn.NIK);
        fprintf(User, "%s\n", KDSignIn.Email);
        fprintf(User, "%s\n", KDSignIn.Password);
        fprintf(User, "%s\n", KDSignIn.BirthPlaceDate);
        fprintf(User, "%s\n", KDSignIn.JobTitle);
        fprintf(User, "%s\n", KDSignIn.HeadRegion);
        fprintf(User, "0\n//// 0 :: UNUSED!\n0\n"); // 0 [1]: Admin fundraising status, 0 [2]: UNUSED, 0 [3]: Client approval status.

        fclose(User);
    }

    snprintf(CreateKDSavings, sizeof(CreateKDSavings) + 16, "KD - %s.txt", KDSignIn.FullName);
    User = fopen(CreateKDSavings, "w");
    fprintf(User, "1000000000000\n\n");
    fclose(User);
}

SektorIndustri SISignIn = { 0 };
char SI_SignInUsername[BUFSIZE07] = { 0 }, SI_SignInPassword[32] = { 0 };
char SIFullName[BUFSIZE07] = { 0 }, SIIndustryName[BUFSIZE07] = { 0 };
int SILoggedIn = 0;
void WritePublicSektorIndustri() {
    int RegisteredSIs = 0;
    char WrittenRegisteredSIs[BUFSIZE07], CreateSISavings[BUFSIZE07];

    if (access(Client_SektorIndustri, F_OK) != 0) {
        Client = fopen(Client_SektorIndustri, "w");

        if (Client == NULL) {
            fprintf(stderr, "ERROR: Tidak dapat menuliskan data pengguna Sektor Industri ke dalam file.\n");
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            HomeMenu();
        }

        fprintf(Client, "1\n\n");
        fprintf(Client, "%s\n", SISignIn.FullName);
        fprintf(Client, "%s\n", SISignIn.IndustryName);
        fprintf(Client, "%s\n", SISignIn.Username);
        fprintf(Client, "%s\n", SISignIn.Password);
        fprintf(Client, "//// 0 :: UNUSED!\n"); // 0 [1]: UNUSED.
        for (int _ = 0; _ < 5; _++) { fprintf(Client, "-, -, -\n"); }
        
        fclose(Client);

    } else {
        RegisteredSIs = atoi(ReadLine(Client_SektorIndustri, AVAILABLE_DATA));
        RegisteredSIs++;
        snprintf(WrittenRegisteredSIs, sizeof(WrittenRegisteredSIs), "%d", RegisteredSIs);
        OverWriteStringAtLine(Client_SektorIndustri, WrittenRegisteredSIs, 0, AVAILABLE_DATA);

        Client = fopen(Client_SektorIndustri, "a");
        fprintf(Client, "\n");
        fprintf(Client, "%s\n", SISignIn.FullName);
        fprintf(Client, "%s\n", SISignIn.IndustryName);
        fprintf(Client, "%s\n", SISignIn.Username);
        fprintf(Client, "%s\n", SISignIn.Password);
        fprintf(Client, "//// 0 :: UNUSED!\n"); // 0 [1]: UNUSED.
        for (int _ = 0; _ < 5; _++) { fprintf(Client, "-, -, -\n"); }

        fclose(Client);
    }

    snprintf(CreateSISavings, sizeof(CreateSISavings) + 16, "SI - %s.txt", SISignIn.FullName);
    Client = fopen(CreateSISavings, "w");
    fprintf(Client, "0\n\n");
    fclose(Client);
}

Keranjang Belanja = { 0 };
void WritePrivateKeranjang(bool WriteForAdmin, bool AddNewCart) {
    if (WriteForAdmin) {
        if (access(AdminCartStore_Keranjang, F_OK) != 0) {
            AdminCart = fopen(AdminCartStore_Keranjang, "w");
            fprintf(AdminCart, "0\n");
            fclose(AdminCart);

        } else {
            if (AddNewCart) {
                char NewStoredCart[BUFSIZE07] = { 0 };

                snprintf(NewStoredCart, sizeof(NewStoredCart), "%d", atoi(ReadLine(AdminCartStore_Keranjang, AVAILABLE_DATA)) + 1);
                OverWriteStringAtLine(AdminCartStore_Keranjang, NewStoredCart, 0, AVAILABLE_DATA);
                
                AdminCart = fopen(AdminCartStore_Keranjang, "a");
                fprintf(AdminCart, "\n%s\n%s\n%s\n%d\n", Belanja.Requester, Belanja.Accepter, Belanja.ProductInDemand, Belanja.Status);
                fclose(AdminCart);
            }
        }

    } else {
        if (access(UserCartStore_Keranjang, F_OK) != 0) {
            UserCart = fopen(UserCartStore_Keranjang, "w");
            fprintf(UserCart, "0\n");
            fclose(UserCart);

        } else {
            if (AddNewCart) {
                char NewStoredCart[BUFSIZE07] = { 0 };

                snprintf(NewStoredCart, sizeof(NewStoredCart), "%d", atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA)) + 1);
                OverWriteStringAtLine(UserCartStore_Keranjang, NewStoredCart, 0, AVAILABLE_DATA);
                
                UserCart = fopen(UserCartStore_Keranjang, "a");
                fprintf(UserCart, "\n%s\n%s\n%s\n%d\n", Belanja.Requester, Belanja.Accepter, Belanja.ProductInDemand, Belanja.Status);
                fclose(UserCart);
            }
        }
    }
}

void AdminMainMenu(void) {
    int AMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AdminMainMenu();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");

    puts("");
    puts("~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~");
    puts("[1] Pengaturan Pajak dan Tabungan Negara");
    puts("[2] Lihat Data Kepala Daerah dan Perekonomiannya");
    puts("[3] Lihat Data Sektor Industri dan Penghasilannya");
    puts("[4] Pendistribusian Bantuan Dana kepada Kepala Daerah");
    puts("[5] Pengaturan Kerja Sama dengan Kepala Daerah");
    puts("[6] Distribusi Perdagangan Skala Internasional");
    puts("[0] Keluar... (Log Out)");

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
    char NewWrittenST[BUFSIZE07] = { 0 };
    float NewST = 0.0f;
    int Options = 0;

    StateProfile.StateTaxes = ReadLine(Admin_Kemenkeu, MF_STATE_TAXES);
    StateProfile.StateSavings = ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS);

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature01();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
    puts("\nMenu: [1] Pengaturan Pajak dan Tabungan Negara");

    puts("");
    puts("Berikut adalah hasil laporan Pajak dan Keuangan Negara:");
    puts("====================================================================================================");
    printf(":: Pajak Negara    (~%%): %.02f%%\n", atof(StateProfile.StateTaxes));
    if (MAX_ADMIN_SAVINGS - atoll(StateProfile.StateSavings) > 0LL)
         { printf(":: Tabungan Negara (Rp): Rp%'lld,00 >> (-Rp%'lld,00)\n", atoll(StateProfile.StateSavings), MAX_ADMIN_SAVINGS - atoll(StateProfile.StateSavings)); }
    else { printf(":: Tabungan Negara (Rp): Rp%'lld,00 >> (+Rp%'lld,00)\n", atoll(StateProfile.StateSavings), atoll(StateProfile.StateSavings) - MAX_ADMIN_SAVINGS); }
    puts("====================================================================================================");

    puts("");
    puts("~ Apakah Anda ingin melakukan perubahan? ~");
    puts("[1] Ubah besar Pajak Negara (%)");
    puts("[2] Lihat alur Perekonomian Negara (Rp)");
    puts("[0] Kembali...");
    AcceptInputOption("> Pilihan Anda: ", Options);

    puts("");
    if (Options == 1) {
        puts("CATATAN: Apabila hendak menyertakan desimal, mohon gunakan tanda koma ',' ...!");
        AcceptF("Sertakan besar persentase pajak negara terbaru (%%): ", NewST);
        
        if (NewST < 0.0f || NewST > 100.0f) {
            puts("ERROR: Persentase Pajak Negara harus berada dalam jangkauan 0.0% hingga 100.0%!");
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            AMMFeature01();
        }

        snprintf(NewWrittenST, sizeof(NewWrittenST), "%.02f", NewST);
        OverWriteStringAtLine(Admin_Kemenkeu, NewWrittenST, 0, MF_STATE_TAXES);

        puts("Pembaruan Pajak Negara telah berhasil!");
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        AMMFeature01();
    
    } else if (Options == 2) {
        ClearScreen();
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [1] Pengaturan Pajak dan Tabungan Negara");

        puts("");
        puts("Berikut adalah hasil laporan Keuangan Negara secara keseluruhan:");
        puts("====================================================================================================");
        if (MAX_ADMIN_SAVINGS - atoll(StateProfile.StateSavings) > 0LL)
             { printf(":: Tabungan Negara (Rp): Rp%'lld,00 >> (-Rp%'lld,00)\n", atoll(StateProfile.StateSavings), MAX_ADMIN_SAVINGS - atoll(StateProfile.StateSavings)); }
        else { printf(":: Tabungan Negara (Rp): Rp%'lld,00 >> (+Rp%'lld,00)\n", atoll(StateProfile.StateSavings), atoll(StateProfile.StateSavings) - MAX_ADMIN_SAVINGS); }
        
        puts("");
        puts("Pemasukkan (Incomes):");
        SearchAll(Admin_Kemenkeu, false, 0, Admin_Kemenkeu" > [+]"); puts("");
        puts("Pengeluaran (Expenses):");
        SearchAll(Admin_Kemenkeu, false, 0, Admin_Kemenkeu" > [-]");
        puts("====================================================================================================");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature02();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
    puts("\nMenu: [2] Lihat Data Kepala Daerah dan Perekonomiannya");

    if (access(User_KepalaDaerah, F_OK) != 0) {
        puts("");
        puts("====================================================================================================");
        puts("Data Kepala Daerah masih kosong!");
        puts("====================================================================================================");

        puts("");
        puts("Mohon maaf, saat ini belum ada Kepala Daerah yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." );
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    }

    puts("");
    puts("Berikut adalah data dari seluruh Kepala Daerah yang terdaftarkan...");

    printf("====================================================================================================");
    for (int KD = 0; KD < atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA)); KD++) {
        MaxKD++;

        strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
        strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
        strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

        snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 16, "KD - %s.txt", KDList.FullName);
        strcpy(KDShownSavings, ReadLine(CurrentFileKD, AVAILABLE_DATA));
        KDShownSavings[strlen(KDShownSavings) - 1] = '\0';

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);
        printf("... Perekonomian Total Daerah: Rp%'lld.00\n", atoll(KDShownSavings));

    } puts("====================================================================================================");

    puts("");
    puts("Sertakan penomoran Kepala Daerah di atas untuk melihat data perekonomian daerah lebih lanjut!");
    puts("(jika tidak, ketik angka 0 untuk kembali ke menu utama Kemenkeu)");
    AcceptInputOption("> Lihat data Kepala Daerah: ", PeekKD);

    if (PeekKD == 0) { AdminMainMenu(); }
    else if (PeekKD > 0 && PeekKD <= (MaxKD + 1)) {
        ClearScreen();
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [2] Lihat Data Kepala Daerah dan Perekonomiannya");

        PeekKD--;
        strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_FULLNAME));
        strcpy(KDList.NIK, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_CIN));
        strcpy(KDList.Email, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_EMAIL));
        strcpy(KDList.BirthPlaceDate, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_BIRTH_DATE));
        strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_DEPARTMENT));
        strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * PeekKD) + HD_DISTRICT_NAME));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';
        KDList.NIK[strlen(KDList.NIK) - 1] = '\0'; KDList.Email[strlen(KDList.Email) - 1] = '\0'; KDList.BirthPlaceDate[strlen(KDList.BirthPlaceDate) - 1] = '\0';

        snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 16, "KD - %s.txt", KDList.FullName);
        
        puts("");
        puts("=== Data Kepala Daerah dan Perekonomiannya ===");
        printf("Yth. Kepala Dserah a.n.: %s, %s %s.\n", KDList.FullName, KDList.JobTitle, KDList.HeadRegion);
        printf(":: NIK/E-mail: %s/%s\n", KDList.NIK, KDList.Email);
        printf(":: Tempat/Tanggal Lahir: %s\n", KDList.BirthPlaceDate);

        strcpy(TotalSavings, ReadLine(CurrentFileKD, AVAILABLE_DATA));
        TotalSavings[strlen(TotalSavings) - 1] = '\0';
        snprintf(KDSSPositive, sizeof(KDSSPositive) + 9, "%s > [+]", CurrentFileKD);
        snprintf(KDSSNegative, sizeof(KDSSNegative) + 9, "%s > [-]", CurrentFileKD);

        puts("");
        puts("====================================================================================================");
        if (MAX_USER_SAVINGS - atoll(TotalSavings) > 0LL)
             { printf(":: Dana Perekonomian Total Daerah: Rp%'lld,00 >> (-Rp%'lld,00)\n", atoll(TotalSavings), MAX_USER_SAVINGS - atoll(TotalSavings)); }
        else { printf(":: Dana Perekonomian Total Daerah: Rp%'lld,00 >> (+Rp%'lld,00)\n", atoll(TotalSavings), atoll(TotalSavings) - MAX_USER_SAVINGS); }

        puts("");
        puts("Pemasukkan (Incomes): ");
        SearchAll(CurrentFileKD, false, 0, KDSSPositive); puts("");
        puts("Pengeluaran (Expenses): ");
        SearchAll(CurrentFileKD, false, 0, KDSSNegative);
        puts("====================================================================================================");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature03();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
    puts("\nMenu: [3] Lihat Data Sektor Industri dan Penghasilannya");

    if (access(Client_SektorIndustri, F_OK) != 0) {
        puts("");
        puts("====================================================================================================");
        puts("Data Sektor Industri masih kosong!");
        puts("====================================================================================================");

        puts("");
        puts("Mohon maaf, saat ini belum ada Sektor Industri yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." );
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    }
    
    puts("");
    puts("Berikut adalah data dari seluruh Sektor Industri yang terdaftarkan...");

    printf("====================================================================================================");
    for (int SI = 0; SI < atoi(ReadLine(Client_SektorIndustri, AVAILABLE_DATA)); SI++) {
        MaxSI++;

        strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * SI) + SI_FULLNAME));
        strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * SI) + SI_INDUSTRY_NAME));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

        snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 16, "SI - %s.txt", SIList.FullName);
        strcpy(SIShownSavings, ReadLine(CurrentFileSI, AVAILABLE_DATA));
        SIShownSavings[strlen(SIShownSavings) - 1] = '\0';

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (SI + 1), SIList.FullName);
        printf("... Nama Industri: %s\n", SIList.IndustryName);
        printf("... Perekonomian Total Industri: Rp%'lld.00\n", atoll(SIShownSavings));

    } puts("====================================================================================================");

    puts("");
    puts("Sertakan penomoran Sektor Industri di atas untuk melihat data perekonomian daerah lebih lanjut!");
    puts("(jika tidak, ketik angka 0 untuk kembali ke menu utama Kemenkeu)");
    AcceptInputOption("> Lihat data Sektor Industri: ", PeekSI);

    if (PeekSI == 0) { AdminMainMenu(); }
    else if (PeekSI > 0 && PeekSI <= (MaxSI + 1)) {
        ClearScreen();
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [3] Lihat Data Sektor Industri dan Penghasilannya");

        PeekSI--;
        strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * PeekSI) + SI_FULLNAME));
        strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * PeekSI) + SI_INDUSTRY_NAME));
        strcpy(SIList.Username, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * PeekSI) + SI_USERNAME));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0'; SIList.Username[strlen(SIList.Username) - 1] = '\0';

        snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 16, "SI - %s.txt", SIList.FullName);
        
        puts("");
        puts("=== Data Perekonomian Sektor Industri ===");
        printf("Yth. Sektor Industri, a.n.: %s, Direktur %s\n", SIList.FullName, SIList.IndustryName);
        printf(":: Kode Klien: %s\n", SIList.Username);

        strcpy(TotalSavings, ReadLine(CurrentFileSI, AVAILABLE_DATA));
        TotalSavings[strlen(TotalSavings) - 1] = '\0';
        snprintf(SISSPositive, sizeof(SISSPositive) + 9, "%s > [+]", CurrentFileSI);

        puts("");
        puts("====================================================================================================");
        printf("Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
        puts("Pemasukkan (Incomes): ");
        SearchAll(CurrentFileSI, false, 0, SISSPositive); puts("");
        puts("Pengeluaran (Expenses): TIDAK ADA PENGELUARAN UNTUK SEKTOR INDUSTRI");
        puts("====================================================================================================");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature04();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
    puts("\nMenu: [4] Pendistribusian Bantuan Dana kepada Kepala Daerah");

    if (access(User_KepalaDaerah, F_OK) != 0) {
        puts("");
        puts("====================================================================================================");
        puts("Data Kepala Daerah masih kosong!");
        puts("====================================================================================================");

        puts("");
        puts("Mohon maaf, saat ini belum ada Kepala Daerah yang mendaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." );
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    }

    AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
    
    puts("");
    puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");
    
    puts("====================================================================================================");
    for (int KD = 0; KD < AvailableKDs; KD++) {
        strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
        strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
        strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

        RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
        else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
        else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
        else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }

        StatusList[KD] = RecentStatus;
        MaxKD++;
        if ((KD + 1) != AvailableKDs) { puts(""); }
    }

    if (MaxKD > 0) { puts("===================================================================================================="); }
    else {
        puts("Data pengajuan bantuan dana dari Kepala Daerah masih kosong!");
        puts("====================================================================================================");

        puts("");
        puts("Mohon maaf, saat ini belum ada Kepala Daerah yang hendak mengajukan bantuan dana kepada Anda...");
        puts("... Silakan untuk ditunggu konfirmasi lanjutannya dan Anda dapat memantau data ini secara berkala..." );
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    }

    puts("");
    puts("Kepada siapa dari pelbagai data Kepala Daerah di atas untuk Anda berikan bantuan dana?");
    puts("(kondisi input sesuai penomoran dari masing-masing Kepala Daerah)");
    puts("(jika ingin kembali ke menu sebelumnya, ketik 0 pada input di bawah)");
    AcceptInputOption("> Pilihan Anda: ", PeekKD);

    if (PeekKD > 0 && PeekKD <= AvailableKDs) {
        ClearScreen();
        
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [4] Pendistribusian Bantuan Dana kepada Kepala Daerah");

        AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));

        puts("");
        puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

        puts("====================================================================================================");
        for (int KD = 0; KD < AvailableKDs; KD++) {
            strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
            strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
            strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
            KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

            if (KD == (PeekKD - 1)) {
                strcpy(GetKDFullName, KDList.FullName); strcpy(GetKDJobTitle, KDList.JobTitle); strcpy(GetKDHeadRegion, KDList.HeadRegion);
                strcpy(KDFileName, "KD - "); strcat(KDFileName, KDList.FullName); strcat(KDFileName, ".txt");

                printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                
                printf(">>> Total Dana Daerah (saat ini): Rp%'lld.00\n", atoll(ReadLine(KDFileName, 1)));
            
            } else {
                printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
            }

            StatusList[KD] = RecentStatus;
            if ((KD + 1) != AvailableKDs) { puts(""); }
        } puts("====================================================================================================");

        puts("");
        if (StatusList[PeekKD - 1] == 0) {
            
            puts("Sepertinya untuk Kepala Daerah yang bersangkutan saat ini TIDAK dalam masa pengajuan permintaan bantuan dana...");
            puts("Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: SEDANG DIPROSES!");
            
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AMMFeature04();

        } else if (StatusList[PeekKD - 1] == 2) {
            puts("Anda telah MENYETUJUI permintaan bantuan dana dari ajuan Kepala Daerah yang bersengakutan sebelumnya...");
            puts("Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: SEDANG DIPROSES!");
            
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AMMFeature04();

        } else if (StatusList[PeekKD - 1] == -1) {
            puts("Anda telah MENOLAK permintaan bantuan dana dari ajuan Kepala Daerah yang bersengakutan sebelumnya...");
            puts("Dipersilakan untuk melakukan re-load dan memilih Kepala Daerah lain yang tengah tertulis: SEDANG DIPROSES!");
            
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AMMFeature04();
        
        } else if (StatusList[PeekKD - 1] == 1) {
            puts("Saat ini Kepala Daerah yang bersangkutan tengah dalam masa pemrosesan dana bantuan dari pihak Anda.");
            puts("... Apakah Anda yakin untuk menerima pengajuan dari beliau, atau harus menolaknya?");
            puts("... Perhatikan bahwa hal ini akan mengurangi nominal tabungan negara, jadi harap dipastikan terlebih dahulu!");
            
            puts("");
            puts("(sertakan Y atau y untuk menyetujui pengajuan, dan N atau n untuk menolak pengajuan)");
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                while (true) {
                    ClearScreen();
            
                    puts("Selamat Datang di aplikasi: D'Wakanda!");
                    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
                    puts("\nMenu: [4] Pendistribusian Bantuan Dana kepada Kepala Daerah");

                    AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
                    OverWriteStringAtLine(User_KepalaDaerah, "2", 0, ((OFFSET_HD + 1) * (PeekKD - 1)) + HD_AID_FUNDS_STATUS);

                    puts("");
                    puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

                    puts("====================================================================================================");
                    for (int KD = 0; KD < AvailableKDs; KD++) {
                        strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
                        strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
                        strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
                        KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                        if (KD == (PeekKD - 1)) {
                            strcpy(GetKDFullName, KDList.FullName); strcpy(GetKDJobTitle, KDList.JobTitle); strcpy(GetKDHeadRegion, KDList.HeadRegion);
                            strcpy(KDFileName, "KD - "); strcat(KDFileName, KDList.FullName); strcat(KDFileName, ".txt");

                            printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                            printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);
                            printf("... Total Dana Daerah (saat ini): Rp%'lld.00\n", atoll(ReadLine(KDFileName, AVAILABLE_DATA)));
                            
                            RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                            if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                            else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                            else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                            else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                        
                        } else {
                            printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                            printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                            RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                            if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                            else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                            else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                            else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                        }

                        StatusList[KD] = RecentStatus;
                        if ((KD + 1) != AvailableKDs) { puts(""); }
                    } puts("====================================================================================================");

                    puts("");
                    puts("Perhatikan arahan di bawah ini, yaitu nominal pemberian harus paling sedikit Rp1,000.00!");
                    AcceptLL("[>= 1000] Berapakah nominal yang Anda kehendaki: ", GivenNomina);
                    
                    if (GivenNomina >= 1000LL) {
                        strcpy(WriteString01_A, ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS));
                        WriteString01_A[strlen(WriteString01_A) - 1] = '\0';
                        snprintf(WriteString02_U, sizeof(WriteString02_U), "%lld", (atoll(WriteString01_A) - GivenNomina));
                        OverWriteStringAtLine(Admin_Kemenkeu, WriteString02_U, 0, MF_STATE_SAVINGS);

                        FILE *CurrentKD = fopen(KDFileName, "a");
                        fprintf(CurrentKD, "[+] Rp%'lld.00: Bantuan Dana dari Kemenkeu\n", (long long int)GivenNomina);
                        fclose(CurrentKD);
                        snprintf(WriteString03_U, sizeof(WriteString03_U), "%lld", atoll(ReadLine(KDFileName, AVAILABLE_DATA)) + GivenNomina);
                        OverWriteStringAtLine(KDFileName, WriteString03_U, 0, AVAILABLE_DATA);

                        strcpy(WriteString01_A, ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS));
                        WriteString01_A[strlen(WriteString01_A) - 1] = '\0';

                        AccessAdmin = fopen(Admin_Kemenkeu, "a");
                        fprintf(AccessAdmin, "[-] Rp%'lld.00: Bantuan Dana kepada Yth. %s, %s %s\n", (long long int)GivenNomina, GetKDFullName, GetKDJobTitle, GetKDHeadRegion);
                        fclose(AccessAdmin);

                        puts("");
                        printf("... Tabungan Negara saat ini: Rp%'lld.00\n", atoll(WriteString01_A));
                        if (atoll(WriteString01_A) < 1000000000) { puts("... Mohon perhatikan tabungan negara berikut dikarenakan agar tidak berhutang!"); }
                        else                                     { puts("... Saat ini tabungan negara masih aman, tingkatkan terus kinerja Anda!"); }
                        puts("Pemberian sumbangan dana tambahan bagi Kepala Daerah yang bersangkutan telah berhasil!");
                        puts("");
                        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                        system("pause"); AMMFeature04();
                
                    } else {
                        OverWriteStringAtLine(User_KepalaDaerah, "1", 0, ((OFFSET_HD + 1) * (PeekKD - 1)) + HD_AID_FUNDS_STATUS);
                        
                        puts("");
                        puts("WARNING: Kesalahan input nominal ditemukan! Nominal yang diberikan tidaklah memenuhi syarat...");
                        puts("... Demi keamanan data, mohon dilakukan penyetelan ulang dari awal pilihan!");
                        puts("");
                        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                        system("pause");
                    }
                }
            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                ClearScreen();
        
                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
                puts("\nMenu: [4] Pendistribusian Bantuan Dana kepada Kepala Daerah");

                AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
                OverWriteStringAtLine(User_KepalaDaerah, "-1", 0, ((OFFSET_HD + 1) * (PeekKD - 1)) + HD_AID_FUNDS_STATUS);

                puts("");
                puts("Berikut adalah data permintaan distribusi dana dari Kepala Daerah...");

                puts("====================================================================================================");
                for (int KD = 0; KD < AvailableKDs; KD++) {
                    strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
                    strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
                    strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
                    KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                    if (KD == (PeekKD - 1)) {
                        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                        RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                        else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                        else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                        else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                    
                    } else {
                        printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                        printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                        RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_AID_FUNDS_STATUS));
                        if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                        else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                        else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                        else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                    }

                    StatusList[KD] = RecentStatus;
                    if ((KD + 1) != AvailableKDs) { puts(""); }
                } puts("====================================================================================================");

                puts("");
                puts("Anda telah memilih untuk MENOLAK pengajuan permintaan dana bantuan dari Kepala Daerah yang bersangkutan!");
                puts("... Dipersilakan untuk kembali ke menu sebelumnya tanpa modifikasi pengguna...");
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); AMMFeature04();
            
            } else { CheckInvalidInput = true; AMMFeature04(); }
        }

    } else if (PeekKD == 0) {
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        AdminMainMenu();

    } else { CheckInvalidInput = true; AMMFeature04(); }
}

void AMMFeature05(void) {
    FILE *AccessCart, *AccessKD;
    Keranjang CartInfo = { 0 };

    char CurrentCartFile[BUFSIZE07];
    char ConfirmRequest, CurrentFileKD[BUFSIZE07] = { 0 }, WriteFinalSavings[BUFSIZE07] = { 0 }, FinalWrittenReqs[BUFSIZE07] = { 0 };
    char DisplayKDFullName[BUFSIZE07] = { 0 }, *DisplayKDJobTitle = "", *DisplayKDHeadRegion = "";
    char DisplaySIFullName[BUFSIZE07] = { 0 }, *DisplaySIIndustryName = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock = "", *DisplayProductPrice = "";
    int AllLinkedRequests[BUFSIZE10] = { 0 }, AllRequestsID[BUFSIZE10] = { 0 };
    int SetNewReqs = 0;
    int AvailableReqs = 0, MaxReq = 0, PeekReq = 0, GetReq = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature05();
    }

    /*
        This "while (true) {...}" method is used to be able to make the user
        traverse around the sub-menu here, so it wouldn't be that much
        necessary to cover the mistakes choosing the given options
        wrongdoingly by going to the main menu and then restart the
        process of asserting inputs from the very beginning.
    */
    while (true) {
        MaxReq = 0;

        ClearScreen();
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah");

        AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));

        puts("");
        puts("Berikut adalah data pengajuan distribusi barang produksi dari Kepala Daerah kepada Anda:");

        puts("====================================================================================================");
        for (int REQ = 0; REQ < AvailableReqs; REQ++) {
            strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_HD_IDENTITY));
            strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_CS_IDENTITY));
            strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
            CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_SELLING_STATUS));

            AllRequestsID[REQ] = REQ;
            if (CartInfo.Status == 2) {
                strcpy(DisplayKDFullName, CartInfo.Requester);
                strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
                strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
                strcpy(DisplaySIFullName, CartInfo.Accepter);
                strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

                MaxReq++;
                AllLinkedRequests[REQ] = MaxReq;

                printf("[%03d] Nama Lengkap: %s\n", MaxReq, DisplayKDFullName);
                printf("... Jabatan/Daerah: %s %s\n", DisplayKDJobTitle, DisplayKDHeadRegion);
                puts("... Status Pengajuan: SEDANG DIPROSES");

                strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                
                puts("");
                printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

                puts("====================================================================================================");
            
            } else { AllLinkedRequests[REQ] = MaxReq; }
        }

        if (MaxReq == 0) {
            puts("Data pengajuan distribusi produk dari Kepala Daerah tengah KOSONG!");
            puts("====================================================================================================");

            puts("");
            puts("PERHATIAN: Saat ini belum ada Kepala Daerah yang hendak mengajukan distribusi barang kepada Kemenkeu!");
            puts("...        Silakan untuk ditunggu dan diperhatikan menu ini secara berkala...");

            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AdminMainMenu();
        }

        puts("");
        printf("Saat ini, tersedia %d PESANAN dari Kepala Daerah yang siap untuk didistribusikan kepada Anda. TERIMA AJUAN sekarang?\n", MaxReq);
        puts("... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini...");
        puts("(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)");
        AcceptInputOption("> Pilihan Anda: ", PeekReq);

        if (PeekReq > 0 && PeekReq <= MaxReq) {
            ClearScreen();

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
            puts("\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah");
            
            for (size_t i = 0; i < sizeof(AllLinkedRequests)/sizeof(AllLinkedRequests[0]); i++) {
                if (AllLinkedRequests[i] != PeekReq) { GetReq++; }
                else { break; }
            }
            
            strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_HD_IDENTITY));
            strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_CS_IDENTITY));
            strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
            CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_SELLING_STATUS));

            strcpy(DisplayKDFullName, CartInfo.Requester);
            strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
            strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
            strcpy(DisplaySIFullName, CartInfo.Accepter);
            strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

            puts("");
            puts("Berikut adalah data keranjang pesanan Kepala Daerah yang siap didistribusikan kepada Anda:");

            puts("====================================================================================================");
            if (CartInfo.Status == 2) {
                printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), DisplayKDFullName);
                printf("... Jabatan/Daerah: %s %s\n", DisplayKDJobTitle, DisplayKDHeadRegion);
                puts("... Status Pengajuan: SEDANG DIPROSES");

                strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                
                puts("");
                printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            } puts("====================================================================================================");
            
            puts("");
            puts("Berikut adalah besar pengeluaran yang Anda keluarkan apabila pihak Anda menerima ajuan distribusi Kepala Daerah yang bersangkutan:");
            printf("Harga Total Pesanan: Rp%'lld.00 (+%0.2f%%) >> Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f))));
            puts("... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Kemenkeu!");
            puts("...          Pengeluaran tersebut akan menjadi pemasukkan bagi Kepala Daerah yang bersangkutan...");

            puts("");
            puts("Setelah melihat data di atas, Anda berhak untuk MENGELOLA permintaan distribusi ini dari Kepala Daerah tersebut. Kelola SEKARANG?");
            puts("... Apabila Anda MENOLAK pengajuan dari yang bersangkutan, Anda masih dapat MENERIMA-nya kembali di lain waktu...");
            
            puts("");
            puts("(ketik Y atau y jika hendak MENERIMA, dan N atau n apabila MENOLAK)");
            puts("(jika ingin kembali ke menu sebelumnya, ketik Q atau q)");
            AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

            if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
                ClearScreen();

                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
                puts("\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah");

                puts("");
                puts("Berikut adalah data keranjang pesanan Kepala Daerah yang TELAH didistribusikan kepada Anda:");

                puts("====================================================================================================");
                if (CartInfo.Status == 2 && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                    printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), DisplayKDFullName);
                    printf("... Jabatan/Daerah: %s %s\n", DisplayKDJobTitle, DisplayKDHeadRegion);
                    puts("... Status Pengajuan: PENGAJUAN DITERIMA");

                    strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
                    DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                    strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                    strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                    
                    puts("");
                    printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                    printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                } puts("====================================================================================================");
                
                strcpy(Belanja.Requester, CartInfo.Requester);
                strcpy(Belanja.Accepter, CartInfo.Accepter);
                snprintf(Belanja.ProductInDemand, sizeof(Belanja.ProductInDemand) + 13, "%s, %s, %lld", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS))/100.0f)));
                Belanja.Status = 0;
                Belanja.Requester[strlen(Belanja.Requester) - 1] = '\0'; Belanja.Accepter[strlen(Belanja.Accepter) - 1] = '\0';
                WritePrivateKeranjang(true, true);

                snprintf(WriteFinalSavings, sizeof(WriteFinalSavings), "%lld", atoll(ReadLine(Admin_Kemenkeu, 4)) - (atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS))/100.0f))));
                OverWriteStringAtLine(Admin_Kemenkeu, WriteFinalSavings, 0, MF_STATE_SAVINGS);

                char WriteNewSavings[BUFSIZE07] = { 0 };
                snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 12, "KD - %s.txt", DisplayKDFullName);
                AccessKD = fopen(CurrentFileKD, "a");
                fprintf(AccessKD, "[+] Rp%'lld.00: Distribusi produk (%s: %s) item, dari Yth. %s, Direktur %s, kepada Kemenkeu\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS))/100.0f)), DisplayProductName, DisplayProductStock, DisplaySIFullName, DisplaySIIndustryName);
                fclose(AccessKD);
                snprintf(WriteNewSavings, sizeof(WriteNewSavings), "%lld", atoll(ReadLine(CurrentFileKD, AVAILABLE_DATA)) + (atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS))/100.0f))));
                OverWriteStringAtLine(CurrentFileKD, WriteNewSavings, 0, AVAILABLE_DATA);

                AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));
                strcpy(CurrentCartFile, "New_"UserCartStore_Keranjang);
                AccessCart = fopen(CurrentCartFile, "w");
                
                fprintf(AccessCart, "0\n");
                for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
                    strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_HD_IDENTITY));
                    strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_CS_IDENTITY));
                    strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_BOUGHT_PRODUCT));
                    CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_SELLING_STATUS));
                    CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
                    
                    if (CartInfo.Status == 2 && ReqID == AllRequestsID[GetReq] && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                        continue;
                    } else {
                        SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                        fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
                    }
                } fclose(AccessCart);

                snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
                OverWriteStringAtLine("New_"UserCartStore_Keranjang, FinalWrittenReqs, 0, AVAILABLE_DATA);
                system("del "UserCartStore_Keranjang);
                rename("New_"UserCartStore_Keranjang, UserCartStore_Keranjang);

                FILE *AccessAdmin = fopen(Admin_Kemenkeu, "a");
                fprintf(AccessAdmin, "[-] Rp%'lld.00: Pembelian produk pada Kepala Daerah (%s: %s) item, dari Yth. %s, %s %s\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)), DisplayProductName, DisplayProductStock, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);
                fclose(AccessAdmin);
                
                puts("");
                puts("Berikut adalah besar pengeluaran yang Anda keluarkan dari persetujuan distribusinya:");
                printf("Besar/Nilai Pengeluaran Anda: Rp%'lld.00 << (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)));
                puts("... CATATAN: Besar pengeluaran di atas akan menimbulkan efek pada Tabungan Negara Anda, jadi mohon untuk dipantau secara berkala!");
                puts("...          Pesanan distribusi yang sudah Anda konfirmasi TIDAK DAPAT Anda batalkan kembali...");

                puts("");
                puts("Status Pengajuan: PENGAJUAN DITERIMA (TIDAK DAPAT DIBATALKAN, PERMANEN)");
                puts(":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah dengan Sektor Industri yang bersangkutan...");
                puts(":: Kini Anda siap untuk mendistribusikan produk pesanan tersebut ke skala INTERNASIONAL!");

                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); AMMFeature05();
            
            } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
                ClearScreen();

                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
                puts("\nMenu: [5] Pengaturan Kerja Sama dengan Kepala Daerah");

                puts("");
                puts("Berikut adalah data keranjang pesanan Kepala Daerah yang MENUNGGU untuk didistribusikan kepada Anda:");

                puts("====================================================================================================");
                if (CartInfo.Status == 2 && strstr(CartInfo.Requester, DisplayKDFullName) != NULL && strstr(CartInfo.Requester, DisplayKDJobTitle) != NULL && strstr(CartInfo.Requester, DisplayKDHeadRegion) != NULL) {
                    printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), DisplayKDFullName);
                    printf("... Jabatan/Daerah: %s %s\n", DisplayKDJobTitle, DisplayKDHeadRegion);
                    puts("... Status Pengajuan: PENGAJUAN DITOLAK");

                    strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
                    DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                    strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                    strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                    
                    puts("");
                    printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
                    printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                } puts("===================================================================================================="); 

                puts("");
                puts("Status Pengajuan: PENGAJUAN DITOLAK (UNTUK SEKARANG, TIDAK PERMANEN)");
                puts(":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                puts(":: Namun jangan khawatir, karena Anda masih dapat MENERIMA pengajuannya kembali di lain waktu!");

                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); AMMFeature05();
            
            } else if (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");
            } else {
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");
            }
        
        } else if (PeekReq == 0) {
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AdminMainMenu();
        } else { CheckInvalidInput = true; AMMFeature05(); }
    }
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AMMFeature06();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
    puts("\nMenu: [6] Distribusi Perdagangan Skala Internasional");

    AvailableReqs = atoi(ReadLine(AdminCartStore_Keranjang, AVAILABLE_DATA));

    puts("");
    puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

    puts("====================================================================================================");
    for (int REQ = 0; REQ < AvailableReqs; REQ++) {
        strcpy(CartInfo.Requester, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_HD_IDENTITY));
        strcpy(CartInfo.Accepter, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_CS_IDENTITY));
        strcpy(CartInfo.ProductInDemand, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
        CartInfo.Status = atoi(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_SELLING_STATUS));

        MaxReq++;
        strcpy(DisplayKDFullName, CartInfo.Requester);
        strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
        strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
        strcpy(DisplaySIFullName, CartInfo.Accepter);
        strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

        strcpy(DisplayProductName, CartInfo.ProductInDemand);
        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
        
        printf("[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", MaxReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);
        printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
        puts("");
        printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

        puts("====================================================================================================");        
    }

    if (MaxReq == 0) {
        puts("Daftar keranjang belanja distribusi produk Anda tengah KOSONG!");
        puts("====================================================================================================");

        puts("");
        puts("PERHATIAN: Saat ini Anda belum menerima daftar keranjang dari Kepala Daerah yang mengajukannya!");
        puts("...        Silakan untuk ditunggu dan diperhatikan menu ini secara berkala...");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    }

    puts("");
    printf("Saat ini, tersedia %d produk di keranjang Anda. DISTRIBUSIKAN SKALA INTERNASIONAL sekarang?\n", MaxReq);
    puts("... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini...");
    puts("(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)");
    AcceptInputOption("> Pilihan Anda: ", PeekReq);

    if (PeekReq > 0 && PeekReq <= MaxReq) {
        ClearScreen();

        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
        puts("\nMenu: [6] Distribusi Perdagangan Skala Internasional");
        
        strcpy(CartInfo.Requester, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_HD_IDENTITY));
        strcpy(CartInfo.Accepter, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_CS_IDENTITY));
        strcpy(CartInfo.ProductInDemand, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_BOUGHT_PRODUCT));
        CartInfo.Status = atoi(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_SELLING_STATUS));

        strcpy(DisplayKDFullName, CartInfo.Requester);
        strtok_r(DisplayKDFullName, ",", &DisplayKDJobTitle); DisplayKDJobTitle = TrimWhiteSpaces(DisplayKDJobTitle);
        strtok_r(DisplayKDJobTitle, ",", &DisplayKDHeadRegion); DisplayKDHeadRegion = TrimWhiteSpaces(DisplayKDHeadRegion);
        strcpy(DisplaySIFullName, CartInfo.Accepter);
        strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);

        puts("");
        puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

        puts("====================================================================================================");
        if      (CartInfo.Status == 0) puts("STATUS REVIEW: ""BELUM DILIHAT");
        else if (CartInfo.Status == 1) puts("STATUS REVIEW: ""TELAH DILIHAT");
        
        puts("");
        printf("[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", PeekReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

        strcpy(DisplayProductName, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_BOUGHT_PRODUCT));
        DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
        strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
        strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
        
        printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
        printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        puts("====================================================================================================");

        puts("");
        puts("Berikut adalah besar pendapatan yang Anda keluarkan apabila pihak Anda mendistribusikan produk yang bersangkutan:");
        printf("Harga Total Pesanan: Rp%'lld.00 (+%0.2f%%) >> Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f))));
        puts("... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Anda sendiri!");

        puts("");
        puts("Setelah melihat data di atas, Anda berhak untuk MENGELOLA distribusi produk tersebut. Kelola SEKARANG?");
        puts("... Apabila Anda belum ingin mendistribusikanya dalam skala internasional, Anda dapat melakukannya di lain waktu...");
        
        puts("");
        puts("(ketik Y atau y jika hendak MENERIMA)");
        puts("(jika ingin kembali ke menu sebelumnya, ketik Q atau q)");
        AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

        if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
            ClearScreen();

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: Admin :: Kementerian Keuangan.");
            puts("\nMenu: [6] Distribusi Perdagangan Skala Internasional");

            puts("");
            puts("Berikut adalah daftar keranjang barang produksi yang telah SIAP didistribusikan ke skala internasional:");

            puts("====================================================================================================");
            if      (CartInfo.Status == 0) puts("STATUS REVIEW: ""BELUM DILIHAT");
            else if (CartInfo.Status == 1) puts("STATUS REVIEW: ""TELAH DILIHAT");
            
            puts("");
            printf("[%03d] Perwakilan Kepala Daaerah: Yth. %s, %s %s\n", PeekReq, DisplayKDFullName, DisplayKDJobTitle, DisplayKDHeadRegion);

            strcpy(DisplayProductName, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekReq - 1)) + CS_BOUGHT_PRODUCT));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            printf("Perwakilan Sektor Industri: Yth %s, Direktur %s.\n", DisplaySIFullName, DisplaySIIndustryName);
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            puts("====================================================================================================");

            AvailableReqs = atoi(ReadLine(AdminCartStore_Keranjang, AVAILABLE_DATA));
            strcpy(CurrentCartFile, "New_"AdminCartStore_Keranjang);
            AccessCart = fopen(CurrentCartFile, "w");

            fprintf(AccessCart, "0\n");
            for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
                strcpy(CartInfo.Requester, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_HD_IDENTITY));
                strcpy(CartInfo.Accepter, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_CS_IDENTITY));
                strcpy(CartInfo.ProductInDemand, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_BOUGHT_PRODUCT));
                CartInfo.Status = atoi(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_SELLING_STATUS));
                CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
                
                if (ReqID == (PeekReq - 1)) {
                    continue;
                } else {
                    SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                    fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
                }
            } fclose(AccessCart);

            snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
            OverWriteStringAtLine("New_"AdminCartStore_Keranjang, FinalWrittenReqs, 0, AVAILABLE_DATA);
            system("del "AdminCartStore_Keranjang);
            rename("New_"AdminCartStore_Keranjang, AdminCartStore_Keranjang);
            
            snprintf(WriteFinalSavings, sizeof(WriteFinalSavings), "%lld", atoll(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS)) + atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)));
            OverWriteStringAtLine(Admin_Kemenkeu, WriteFinalSavings, 0, MF_STATE_SAVINGS);

            FILE *AccessAdmin = fopen(Admin_Kemenkeu, "a");
            fprintf(AccessAdmin, "[+] Rp%'lld.00: Distribusi produk (%s: %s) item, dari Yth. %s, Direktur %s, skala Internasional\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)), DisplayProductName, DisplayProductStock, DisplaySIFullName, DisplaySIIndustryName);
            fclose(AccessAdmin);
            
            puts("");
            puts("Berikut adalah besar pendapatan yang Anda terima dari persetujuan distribusinya:");
            printf("Besar/Nilai Pendapatan Anda: Rp%'lld.00 << (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)));
            puts("... CATATAN: Besar pendapatan di atas akan menimbulkan efek pada Tabungan Negara Anda, jadi mohon untuk dipantau secara berkala!");
            puts("...          Pesanan distribusi yang sudah Anda konfirmasi TIDAK DAPAT Anda batalkan kembali...");

            puts("");
            puts("Status Distribusi: DISTRIBUSI SUKSES (TIDAK DAPAT DIBATALKAN, PERMANEN)");
            puts(":: Selamat, Anda telah mendistribusikan barang produksi yang bersangkutan ke skala internasional...");

            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AMMFeature06();
        
        } else if (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); AMMFeature06();
        } else { CheckInvalidInput = true; AMMFeature06(); }
    
    } else if (PeekReq == 0) {
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); AdminMainMenu();
    } else { CheckInvalidInput = true; AMMFeature06(); }
}

void UserMainMenu(void) {
    int UMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        AdminMainMenu();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
    printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);

    puts("");
    puts("~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~");
    puts("[1] Lihat Alur Perekonomian Dana Daerah");
    puts("[2] Pengajuan Dana Bantuan dari Kementerian Keuangan");
    puts("[3] Distribusi Perdagangan kepada Kementerian Keuangan");
    puts("[4] Pengaturan Kerja Sama dengan Sektor Industri");
    puts("[0] Keluar... (Log Out)");

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
    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
    printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
    puts("\nMenu: [1] Lihat Alur Perekonomian Dana Daerah");

    snprintf(CurrentFileKD, sizeof(CurrentFileKD) + 12, "KD - %s.txt", KDFullName);

    strcpy(TotalSavings, ReadLine(CurrentFileKD, AVAILABLE_DATA));
    TotalSavings[strlen(TotalSavings) - 1] = '\0';
    snprintf(KDSSPositive, sizeof(KDSSPositive) + 9, "%s > [+]", CurrentFileKD);
    snprintf(KDSSNegative, sizeof(KDSSNegative) + 9, "%s > [-]", CurrentFileKD);

    puts("");
    puts("Berikut adalah data akumulasi perekonomian dana daerah dari yang bersangkutan:");
    puts("====================================================================================================");
    if (MAX_USER_SAVINGS - atoll(TotalSavings) > 0LL)
         { printf(":: Dana Perekonomian Total Daerah: Rp%'lld,00 >> (-Rp%'lld,00)\n", atoll(TotalSavings), MAX_USER_SAVINGS - atoll(TotalSavings)); }
    else { printf(":: Dana Perekonomian Total Daerah: Rp%'lld,00 >> (+Rp%'lld,00)\n", atoll(TotalSavings), atoll(TotalSavings) - MAX_USER_SAVINGS); }

    puts("");
    puts("Pemasukkan (Incomes): ");
    SearchAll(CurrentFileKD, false, 0, KDSSPositive); puts("");
    puts("Pengeluaran (Expenses): ");
    SearchAll(CurrentFileKD, false, 0, KDSSNegative);
    puts("====================================================================================================");

    puts("");
    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
    system("pause");
    UserMainMenu();
}

void UMMFeature02(void) {
    char OpenRequest = 0;
    int RecentStatus = 0;
    
    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        UMMFeature02();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
    printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
    puts("\nMenu: [2] Pengajuan Dana Bantuan dari Kementerian Keuangan");

    RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KDLoggedIn) + HD_AID_FUNDS_STATUS));
    
    puts("");
    puts("====================================================================================================");
    puts("Berikut adalah status permintaan bantuan dana Anda saat ini:");
    if      (RecentStatus == 0)  { puts(":: Status Permintaan: -"); }
    else if (RecentStatus == 1)  { puts(":: Status Permintaan: SEDANG DIPROSES"); }
    else if (RecentStatus == 2)  { puts(":: Status Permintaan: PENGAJUAN DITERIMA"); puts(":: Anda dapat melihat nominal pemberian dari Kemenkeu pada menu Alur Perekonomian Daerah Anda... "); }
    else if (RecentStatus == -1) { puts(":: Status Permintaan: PENGAJUAN DITOLAK"); }
    puts("====================================================================================================");

    puts("");
    if (RecentStatus == 0 || RecentStatus == 2 || RecentStatus == -1) {
        puts("Ajukan permintaan bantuan dana kepada pihak Kemenkeu?");
        puts("(ketik Y atau y jika hendak mengajukan)");
        puts("(ketik Q atau q untuk keluar...)");
        AcceptCharInput("> Pilihan Anda: ", OpenRequest);
        
        if (OpenRequest == 'Y' || OpenRequest == 'y') {
            ClearScreen();

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
            printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
            puts("\nMenu: [2] Pengajuan Dana Bantuan dari Kementerian Keuangan");

            OverWriteStringAtLine(User_KepalaDaerah, "1", 0, ((OFFSET_HD + 1) * KDLoggedIn) + HD_AID_FUNDS_STATUS);
            RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KDLoggedIn) + HD_AID_FUNDS_STATUS));
            
            puts("");
            puts("====================================================================================================");
            puts("Berikut adalah status permintaan bantuan dana Anda saat ini:");
            if      (RecentStatus == 0)  { puts(":: Status Permintaan: -"); }
            else if (RecentStatus == 1)  { puts(":: Status Permintaan: SEDANG DIPROSES"); }
            else if (RecentStatus == 2)  { puts(":: Status Permintaan: PENGAJUAN DITERIMA"); puts(":: Anda dapat melihat nominal pemberian dari Kemenkeu pada menu Alur Perekonomian Daerah Anda... "); }
            else if (RecentStatus == -1) { puts(":: Status Permintaan: PENGAJUAN DITOLAK"); }
            puts("====================================================================================================");
            
            puts("");
            puts("Pengajuan permintaan bantuan dana telah berhasil!");
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            UMMFeature02();
            
        } else if (OpenRequest == 'Q' || OpenRequest == 'q') {            
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            UserMainMenu();
        } else { CheckInvalidInput = true; UMMFeature02(); }

    } else if (RecentStatus == 1) {
        puts("Saat ini permintaan bantuan dana Anda sedang diproses!");
        puts("Harap untuk menunggu hasil keputusan dari pihak Kemenkeu mengenai pengajuan bantuan dana Anda...");
        
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        UserMainMenu();
    }
}

void UMMFeature03(void) {
    Keranjang CartInfo = { 0 };
    char ConfirmRequest;
    char DisplaySIFullName[BUFSIZE07] = { 0 }, *DisplaySIIndustryName = "";
    char DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock = "", *DisplayProductPrice = "";
    int AllLinkedRequests[BUFSIZE10] = { 0 }, AllRequestsID[BUFSIZE10] = { 0 };
    int AvailableConfirms = 0, AvailableReqs = 0, MaxConfirms = 0, MaxReq = 0, PeekReq = 0, GetReq = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        UMMFeature03();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
    printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
    puts("\nMenu: [3] Distribusi kepada Kementerian Keuangan");

    AvailableConfirms = atoi(ReadLine(AdminCartStore_Keranjang, AVAILABLE_DATA));

    for (int ACC = 0; ACC < AvailableConfirms; ACC++) {
        if (strstr(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_HD_IDENTITY), KDFullName) != NULL && strstr(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_HD_IDENTITY), KDJobTitle) != NULL && strstr(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_HD_IDENTITY), KDHeadRegion)) {
            if (atoi(ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_SELLING_STATUS)) == 0) {
                MaxConfirms++;
                OverWriteStringAtLine(AdminCartStore_Keranjang, "1", 0, ((OFFSET_CS + 1) * ACC) + CS_SELLING_STATUS);
                
                puts("====================================================================================================");
                puts("Status Pengajuan: PENGAJUAN DITERIMA");
                puts(":: Selamat, pengajuan distribusi produk Anda telah diterima oleh Kemenkeu!");
                puts(":: Berikut informasi produk yang bersangkutan... Semangat berbisnis!");

                strcpy(DisplaySIFullName, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_CS_IDENTITY));
                DisplaySIFullName[strlen(DisplaySIFullName) - 1] = '\0';
                strtok_r(DisplaySIFullName, ",", &DisplaySIIndustryName); DisplaySIIndustryName = TrimWhiteSpaces(DisplaySIIndustryName);
                strcpy(DisplayProductName, ReadLine(AdminCartStore_Keranjang, ((OFFSET_CS + 1) * ACC) + CS_BOUGHT_PRODUCT));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);

                puts("");
                printf("[%03d] Sektor Industri :: Yth. %s, Direktur %s\n", MaxConfirms, DisplaySIFullName, DisplaySIIndustryName);
                printf("... Nama dan Stok Produk: %s, %s item\n", DisplayProductName, DisplayProductStock);
                printf("... Pendapatan Total (+Bonus Pajak): Rp%'lld.00\n", atoll(DisplayProductPrice));
            }
        }
    } if (MaxConfirms > 0) {
        puts("====================================================================================================");
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UMMFeature03();
    }

    AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));

    puts("");
    puts("Berikut adalah data keranjang pelbagai pesanan Anda yang SIAP didistribusikan kepada Kemenkeu:");

    puts("====================================================================================================");
    for (int REQ = 0; REQ < AvailableReqs; REQ++) {
        strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_HD_IDENTITY));
        strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_CS_IDENTITY));
        strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
        CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_SELLING_STATUS));

        AllRequestsID[REQ] = REQ;
        if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            MaxReq++; AllLinkedRequests[REQ] = MaxReq;

            printf("[%03d] Nama Lengkap: %s\n", (MaxReq), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n", KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: SIAP DIDISTRIBUSIKAN");

            strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

            puts("====================================================================================================");
        
        } else if (CartInfo.Status == 2 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            MaxReq++; AllLinkedRequests[REQ] = MaxReq;

            printf("[%03d] Nama Lengkap: %s\n", (MaxReq), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n", KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: SEDANG DIPROSES");

            strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));

            puts("====================================================================================================");
        
        } else { AllLinkedRequests[REQ] = MaxReq;  }
    }

    if (MaxReq == 0) {
        puts("Daftar keranjang pesanan produk Anda dari Sektor Industri tengah KOSONG!");
        puts("====================================================================================================");

        puts("");
        puts("PERHATIAN: Saat ini Anda belum ada membeli produk dari Sektor Industri yang hendak diajukan ke kepada Kemenkeu!");
        puts("...        Anda diperkenankan untuk memesan produk dari Sektor Industri terlebih dahulu...");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UserMainMenu();
    }

    puts("");
    printf("Saat ini, tersedia %d PESANAN Anda yang siap untuk didistribusikan kepada Kemenkeu. Distribusikan sekarang?\n", MaxReq);
    puts("... Kondisi penomoran data pesanan di atas disesuaikan untuk sesi input ini...");
    puts("(untuk membatalkan, ketik 0 untuk kembali ke menu sebelumnya)");
    AcceptInputOption("> Pilihan Anda: ", PeekReq);

    if (PeekReq > 0 && PeekReq <= MaxReq) {
        ClearScreen();

        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
        printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
        puts("\nMenu: [3] Distribusi kepada Kementerian Keuangan");
        
        for (size_t i = 0; i < sizeof(AllLinkedRequests)/sizeof(AllLinkedRequests[0]); i++) {
            if (AllLinkedRequests[i] != PeekReq) { GetReq++; }
            else { break; }
        }
        
        strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_HD_IDENTITY));
        strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_CS_IDENTITY));
        strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
        CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_SELLING_STATUS));

        puts("");
        puts("Berikut adalah data keranjang pesanan Anda yang SIAP didistribusikan kepada Kemenkeu:");

        puts("====================================================================================================");
        if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n", KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: SIAP DIDISTRIBUSIKAN");

            strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        
        } else if (CartInfo.Status == 2 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
            printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), KDFullName);
            printf("... Jabatan/Daerah: %s %s\n", KDJobTitle, KDHeadRegion);
            puts("... Status Pengajuan: SEDANG DIPROSES");

            strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
            DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
            strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
            strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
            
            puts("");
            printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
        } puts("====================================================================================================");

        if (CartInfo.Status == 2) {
            puts("");
            puts("Status Pengajuan: SEDANG DIPROSES");
            puts(":: Sebelumnya Anda telah melakukan pengajuan distribusi barang produksi dari Sektor Industri kepada Kemenkeu...");
            puts(":: Harap untuk menunggu informasi lebih lanjut dari pihak Kemenkeu mengenai pengajuan Anda berikut ini!");
            
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); UMMFeature03();
        }
        
        puts("");
        puts("Berikut adalah hasil pendapatan yang Anda terima apabila pihak Kemenkeu menerima ajuan distribusi Anda:");
        printf("... Harga Total: Rp%'lld.00 (+%0.2f%%) >> Rp%'lld.00\n", atoll(DisplayProductPrice), atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS)), (long long int)round(atoll(DisplayProductPrice) + (atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_SAVINGS))/100.0f))));
        puts("... CATATAN: Perolehan keuntungan didapat dari besar persentase Pajak Negara yang diatur Kemenkeu!");

        puts("");
        puts("Setelah melihat data di atas, Anda berhak untuk MENGAJUKAN permintaan distribusi ini ke Kemenkeu. Ajukan SEKARANG?");
        puts("(ketik Y atau y jika setuju, dan N atau n jika tidak setuju)");
        puts("(jika ingin kembali ke menu sebelumnya, ketik Q atau q)");
        AcceptCharInput("> Pilihan Anda: ", ConfirmRequest);

        if (ConfirmRequest == 'Y' || ConfirmRequest == 'y') {
            ClearScreen();

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
            printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
            puts("\nMenu: [3] Distribusi kepada Kementerian Keuangan");

            puts("");
            puts("Berikut adalah data keranjang pesanan Anda yang siap didistribusikan kepada Kemenkeu:");

            strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_HD_IDENTITY));
            strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_CS_IDENTITY));
            strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
            CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_SELLING_STATUS));

            puts("====================================================================================================");
            if (CartInfo.Status == 1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
                printf("[%03d] Nama Lengkap: %s\n", (GetReq + 1), KDFullName);
                printf("... Jabatan/Daerah: %s %s\n", KDJobTitle, KDHeadRegion);
                puts("... Status Pengajuan: SEDANG DIPROSES");

                strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_BOUGHT_PRODUCT));
                DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                
                puts("");
                printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
            } puts("====================================================================================================");

            OverWriteStringAtLine(UserCartStore_Keranjang, "2", 0, ((OFFSET_CS + 1) * AllRequestsID[GetReq]) + CS_SELLING_STATUS);
            
            puts("");
            puts("Berikut adalah hasil pendapatan yang Anda terima apabila pihak Kemenkeu menerima ajuan distribusi Anda:");
            printf("... Pendapatan Penjualan Anda (sementara): Rp%'lld.00 << (+Rp%'lld.00)\n", atoll(DisplayProductPrice) + (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)), (long long int)round(atoll(DisplayProductPrice) * (atof(ReadLine(Admin_Kemenkeu, MF_STATE_TAXES))/100.0f)));
            puts("... CATATAN: Anda baru HANYA MENDAPATKAN penghasilan di atas apabila Kemenkeu telah MENYETUJUINYA terlebih dahulu!");
            puts("...          Sebagai informasi, Anda dapat MEMBATALKAN pengajuan ini secara sepihak dari Anda sendiri setelahnya...");

            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); UMMFeature03();
        
        } else if (ConfirmRequest == 'N' || ConfirmRequest == 'n') {
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); UMMFeature03();
        } else if   (ConfirmRequest == 'Q' || ConfirmRequest == 'q') {
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause"); UserMainMenu();
        } else { puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
        }
    
    } else if (PeekReq == 0) {
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        UMMFeature04();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
    printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
    puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");

    KDRequestStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KDLoggedIn) + HD_SI_BOUGHT_PRODUCT_STATUS));

    puts("");
    if (KDRequestStatus == 1) {
        puts("Status Pengajuan: SEDANG DIPROSES");
        puts(":: Sebelumnya Anda telah melakukan pemesanan barang produksi dari Sektor Industri...");
        puts(":: Perhatikan bahwa tindakan tersebut TIDAK DAPAT Anda batalkan kembali, jadi mohon untuk ditunggu konfirmasinya!");
        
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UserMainMenu();

    } else if (KDRequestStatus == 2) {
        OverWriteStringAtLine(User_KepalaDaerah, "0", 0, ((OFFSET_HD + 1) * KDLoggedIn) + HD_SI_BOUGHT_PRODUCT_STATUS);

        puts("Status Pengajuan: PENGAJUAN DITERIMA");
        puts(":: Selamat telah menyelesaikan transaksi barang produksi pesanan Anda dengan Sektor Industri yang bersangkutan...");
        puts(":: Saat ini Anda dapat memesan barang produksi Sektor Industri kembali, jadi silakan untuk di-refresh kembali!");
        
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UMMFeature04();

    } else if (KDRequestStatus == -1) {
        OverWriteStringAtLine(User_KepalaDaerah, "0", 0, ((OFFSET_HD + 1) * KDLoggedIn) + HD_SI_BOUGHT_PRODUCT_STATUS);

        AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));
        strcpy(CurrentCartFile, "New_"UserCartStore_Keranjang);
        AccessCart = fopen(CurrentCartFile, "w");
        
        fprintf(AccessCart, "0\n");
        for (int ReqID = 0; ReqID < AvailableReqs; ReqID++) {
            strcpy(CartInfo.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_HD_IDENTITY));
            strcpy(CartInfo.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_CS_IDENTITY));
            strcpy(CartInfo.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_BOUGHT_PRODUCT));
            CartInfo.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * ReqID) + CS_SELLING_STATUS));
            CartInfo.Requester[strlen(CartInfo.Requester) - 1] = '\0'; CartInfo.Accepter[strlen(CartInfo.Accepter) - 1] = '\0'; CartInfo.ProductInDemand[strlen(CartInfo.ProductInDemand) - 1] = '\0';
            
            if (CartInfo.Status == -1 && strstr(CartInfo.Requester, KDFullName) != NULL && strstr(CartInfo.Requester, KDJobTitle) != NULL && strstr(CartInfo.Requester, KDHeadRegion) != NULL) {
                continue;
            } else {
                SetNewReqs++; // Guarantee to be always - 1 by ALL requests before!
                fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CartInfo.Requester, CartInfo.Accepter, CartInfo.ProductInDemand, CartInfo.Status);
            }
        } fclose(AccessCart);

        snprintf(FinalWrittenReqs, sizeof(FinalWrittenReqs), "%d", SetNewReqs);
        OverWriteStringAtLine("New_"UserCartStore_Keranjang, FinalWrittenReqs, 0, AVAILABLE_DATA);
        system("del "UserCartStore_Keranjang);
        rename("New_"UserCartStore_Keranjang, UserCartStore_Keranjang);

        puts("Status Pengajuan: PENGAJUAN DITOLAK");
        puts(":: Walaupun pengajuan pemesanan Anda ditolak, namun jangan khawatir karena Anda bisa memesan yang lainnya...");
        puts(":: Saat ini Anda dapat memesan barang produksi Sektor Industri kembali, jadi silakan untuk di-refresh kembali!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UMMFeature04();
    }
    
    puts("Berikut adalah data dari seluruh Sektor Industri yang tersedia...");
    printf("====================================================================================================");
    for (int SI = 0; SI < atoi(ReadLine(Client_SektorIndustri, AVAILABLE_DATA)); SI++) {
        strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * SI) + SI_FULLNAME));
        strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * SI) + SI_INDUSTRY_NAME));
        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';
        MaxSI++;

        puts("");
        printf("[%03d] Nama Lengkap: %s\n", (SI + 1), SIList.FullName);
        printf("... Nama Industri: %s\n", SIList.IndustryName);
    }

    if (MaxSI > 0) { puts("===================================================================================================="); }
    else {
        puts("");
        puts("Data Sektor Industri belum tersedia!");
        puts("====================================================================================================");

        puts("");
        puts("Mohon maaf, untuk saat ini belum ada data Sektor Industri yang terdaftar...");
        puts("... Silakan untuk ditunggu konfirmasi lebih lanjutnya dari pihak Sektor Industri yang mendaftar, ");
        puts("... dan dimohon untuk dinantikan dan dipantau menu ini secara berkala...");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UserMainMenu();
    }

    puts("");
    puts("Sertakan penomoran Sektor Industri di atas untuk melihat data Sektor Industri yang bersangkutan dengan lebih detail!");
    puts("(jika tidak, ketik angka 0 untuk kembali ke menu utama Kepala Daerah)");
    AcceptInputOption("> Lihat data Sektor Industri: ", PeekSI);

    if (PeekSI > 0 && PeekSI < (MaxSI + 1)) {
        while (true) {
            if (RecentStatus == 0) {
                ClearScreen();
                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
                printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");
                        
                puts("");
                puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_FULLNAME));
                strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_INDUSTRY_NAME));
                SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                puts("====================================================================================================");
                printf("[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                printf("... Nama Industri: %s\n", SIList.IndustryName);
                puts("====================================================================================================");

                puts("");
                puts("Mohon maaf, tapi saat ini Sektor Industri yang bersangkutan sedang TIDAK menerima pengajuan kerja sama dengan Kepala Daerah!");
                puts("... Silakan untuk memilih Sektor Industri lainnya...");
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); UMMFeature04();
            }

            ClearScreen();
            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
            printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
            puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");
                    
            puts("");
            puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

            strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_FULLNAME));
            strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_INDUSTRY_NAME));
            SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

            puts("====================================================================================================");
            printf("[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
            printf("... Nama Industri: %s\n", SIList.IndustryName);
            puts("====================================================================================================");
            
            for (int SI = 0; SI < MaxStocks; SI++) {
                strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * (PeekSI - 1)) + (SI_PRODUCT_NO_1 + SI))));
                CheckStock[strlen(CheckStock) - 1] = '\0';

                if (strcmp(CheckStock, "-, -, -") == 0) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }
                else {
                    strcpy(ProductName, CheckStock);
                    strtok_r(ProductName, ",", &ProductStock);
                    strtok_r(ProductStock, ",", &ProductPrice);
                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                    AvailableStocks++; InStocks[SI] = 1;
                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                    printf("...  Stok Produk: %s\n", ProductStock);
                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                    if (SI != (MaxStocks - 1)) { puts(""); }
                }
            } puts("====================================================================================================");

            puts("");
            puts("Sertakan penomoran produk ID antara 1 sampai 5 seperti yang tertera di atas!");
            puts("(jika tidak, ketik angka 0 untuk kembali ke menu sebelumnya)");
            AcceptInputOption("> [1][2][3][4][5] Ajukan Pembelian Produk: ", PeekStockID);

            if (PeekStockID > 0 && PeekStockID <= MaxStocks) {
                while (true) {
                    if (InStocks[PeekStockID - 1] == 1) {
                        ClearScreen();

                        puts("Selamat Datang di aplikasi: D'Wakanda!");
                        puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
                        printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                        puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");
                                
                        puts("");
                        puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                        strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_FULLNAME));
                        strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_INDUSTRY_NAME));
                        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                        puts("====================================================================================================");
                        printf("[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                        printf("... Nama Industri: %s\n", SIList.IndustryName);
                        puts("====================================================================================================");
                        
                        for (int SI = 0; SI < MaxStocks; SI++) {
                            strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * (PeekSI - 1)) + (SI_PRODUCT_NO_1 + SI))));
                            CheckStock[strlen(CheckStock) - 1] = '\0';

                            if (strchr(CheckStock, '-') != NULL) {
                                if (PeekStockID == (SI + 1)) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }
                            } else {
                                strcpy(ProductName, CheckStock);
                                strtok_r(ProductName, ",", &ProductStock);
                                strtok_r(ProductStock, ",", &ProductPrice);
                                ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                AvailableStocks++;
                                if (PeekStockID == (SI + 1)) {
                                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                    strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                } if (SI != (MaxStocks - 1)) { puts(""); }
                            }
                        } puts("====================================================================================================");

                        if (atoll(DisplayProductStock) == 0LL) {
                            puts("");
                            puts(":: STATUS: TIDAK MENCUKUPI");
                            puts(":: STOK PRODUK: 0");
                            puts("Maaf, Anda tidak dapat memesan produk yang bersangkutan karena belum diisi kembali oleh Sektor Industri yang bersangkutan!");
                            puts("Silakan untuk memilih produk lainnya yang masih tersedia...");
                            
                            puts("");
                            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                            system("pause"); break;
                        }

                        puts("");
                        puts("Sertakan banyaknya produk yang ingin dipesan kepada Sektor Industri yang bersangkutan!");
                        puts("... PERHATIKAN bahwa data yang sudah DISERTAKAN dan DISETUJUI oleh pengguna TIDAK DAPAT DIUBAH ataupun\n... DIBATALKAN kembali selama belum TERKONFIRMASI oleh pihak Sektor Industri yang bersangkutan!");
                        puts("... Catatan: Jika input dibiarkan kosong, maka nilai default-nya AKAN MENJADI total stok produk saat ini...");
                        puts("...          Jika nilai input pesanan stok produk tidak sesuai, maka nilai default-nya JUGA AKAN MENJADI\n...          total stok produk saat ini...");
                        printf("[1 <= ??? <= %s]: (sudah jelas)\n", DisplayProductStock);
                        
                        puts("");
                        AcceptInputText("> Banyak stok produk yang ingin dipesan: ", NewProductStock);
                        NewProductStock[strlen(NewProductStock) - 1] = '\0';

                        if (strlen(NewProductStock) == 0 || atoll(NewProductStock) > atoll(DisplayProductStock)) { strcpy(NewProductStock, DisplayProductStock); }                
                        if (atoll(NewProductStock) < 1LL) {
                            puts("");
                            puts("WARNING: Sesuai dengan penjelasan di atas, nilai stok produk yang dipesan HARUS >= 1!");
                            puts("Demi keamaan, harap untuk diulang kembali dan dimohon untuk DIPERHATIKAN perintah yang diminta!");
                            puts("");
                            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                            system("pause");

                        } else {
                            snprintf(KDFile, sizeof(KDFile) + 12, "KD - %s.txt", KDFullName);
                            strcpy(BeforeSavings, ReadLine(KDFile, AVAILABLE_DATA));
                            BeforeSavings[strlen(BeforeSavings) - 1] = '\0';
                            snprintf(AfterSavings, sizeof(AfterSavings), "%lld", atoll(BeforeSavings) - (atoll(DisplayProductPrice) * atoll(NewProductStock)));

                            ClearScreen();
                            puts("Selamat Datang di aplikasi: D'Wakanda!");
                            puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
                            printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                            puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");

                            puts("");
                            puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                            strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_FULLNAME));
                            strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_INDUSTRY_NAME));
                            SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                            puts("====================================================================================================");
                            printf("[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                            printf("... Nama Industri: %s\n", SIList.IndustryName);
                            puts("====================================================================================================");

                            for (int SI = 0; SI < MaxStocks; SI++) {
                                strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * (PeekSI - 1)) + (SI_PRODUCT_NO_1 + SI))));
                                CheckStock[strlen(CheckStock) - 1] = '\0';

                                if (strchr(CheckStock, '-') != NULL) {
                                    if (PeekStockID == (SI + 1)) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }
                                    // else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                                } else {
                                    strcpy(ProductName, CheckStock);
                                    strtok_r(ProductName, ",", &ProductStock);
                                    strtok_r(ProductStock, ",", &ProductPrice);
                                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                    AvailableStocks++;
                                    if (PeekStockID == (SI + 1)) {
                                        printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                        printf("...  Stok Produk: %s\n", ProductStock);
                                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                        strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                    } if (SI != (MaxStocks - 1)) { puts(""); }
                                }
                            } puts("====================================================================================================");

                            puts("");
                            puts("Apakah Anda sudah yakin dengan banyak stok yang telah Anda pesan?");
                            printf("... Stok produk saat ini dan setelahnya:\n... ... %lld >> %lld\n", atoll(DisplayProductStock), atoll(DisplayProductStock) - atoll(NewProductStock));
                            printf("... Saldo perekonomian Anda saat ini dan setelahnya:\n... ... Rp%'lld.00 >> Rp%'lld.00 (-Rp%'lld.00)\n", atoll(BeforeSavings), atoll(AfterSavings), atoll(BeforeSavings) - atoll(AfterSavings));
                            
                            puts("");
                            puts("(ketik Y atau y apabila sudah yakin, dan N atau n jika ingin dipastikan kembali)");
                            puts("(ketik X atau x untuk kembali ke pemilihan produk, dan Q atau q untuk memilih kembali dari awal mula)");
                            AcceptCharInput("> Pilihan Anda: ", ConfirmStockInput);

                            if (ConfirmStockInput == 'Y' || ConfirmStockInput == 'y') {
                                snprintf(Belanja.Requester, (sizeof(Belanja.Requester) * 3) + 11, "%s, %s, %s", KDFullName, KDJobTitle, KDHeadRegion);
                                snprintf(Belanja.Accepter, (sizeof(Belanja.Accepter) * 2) + 7, "%s, %s", SIList.FullName, SIList.IndustryName);
                                snprintf(Belanja.ProductInDemand, (sizeof(Belanja.ProductInDemand) * 3) + 13, "%s, %s, %lld", DisplayProductName, NewProductStock, (atoll(DisplayProductPrice) * atoll(NewProductStock)));
                                Belanja.Status = 0;

                                WritePrivateKeranjang(false, true);
                                OverWriteStringAtLine(User_KepalaDaerah, "1", 0, ((OFFSET_SI + 1) * KDLoggedIn) + HD_SI_BOUGHT_PRODUCT_STATUS);

                                ClearScreen();
                                puts("Selamat Datang di aplikasi: D'Wakanda!");
                                puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
                                printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                                puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");

                                puts("");
                                puts("Anda telah berhasil memesan produk distribusi dari Sektor Industri yang bersangkutan!");
                                puts("Dimohon untuk ditunggu informasi lebih lanjut, karena data pengiriman pesanan masihbersifat sementara...");
                                puts("... Pastikan status pesanan Anda untuk melihat bagaimana respons dari pihak Sektor Industri tersebut!");

                                puts("");
                                puts("Pesanan Anda meliputi sebagai berikut:");
                                printf("[KD] Pengajuan dari Yth. %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                                printf("[SI] Pengelola kepada Yth. %s, Direktur dari %s.\n", SIList.FullName, SIList.IndustryName);
                                printf("... 1. Nama Produk: %s\n... 2. Stok Pesanan: %s\n... 3. Harga Total: Rp%'lld.00\n", DisplayProductName, NewProductStock, (atoll(DisplayProductPrice) * atoll(NewProductStock)));

                                puts("");
                                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                                system("pause"); UMMFeature04();
                            }
                            
                            else if (ConfirmStockInput == 'N' || ConfirmStockInput == 'n') {
                                puts("");
                                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                                system("pause");
                            } else if (ConfirmStockInput == 'X' || ConfirmStockInput == 'x') {
                                puts("");
                                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                                system("pause"); break;
                            } else if (ConfirmStockInput == 'Q' || ConfirmStockInput == 'q') {
                                puts("");
                                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                                system("pause"); UMMFeature04();
                            }
                        }

                    } else if (InStocks[PeekStockID - 1] == 0) {
                        ClearScreen();

                        puts("Selamat Datang di aplikasi: D'Wakanda!");
                        puts("Anda tengah masuk sebagai: User :: Kepala Daerah.");
                        printf("... Profil Kepala Daerah: %s, %s %s.\n", KDFullName, KDJobTitle, KDHeadRegion);
                        puts("\nMenu: [4] Pengaturan Kerja Sama dengan Sektor Industri");
                                
                        puts("");
                        puts("Berikut adalah data dari seluruh Sektor Industri yang bersangkutan...");

                        strcpy(SIList.FullName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_FULLNAME));
                        strcpy(SIList.IndustryName, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * (PeekSI - 1)) + SI_INDUSTRY_NAME));
                        SIList.FullName[strlen(SIList.FullName) - 1] = '\0'; SIList.IndustryName[strlen(SIList.IndustryName) - 1] = '\0';

                        puts("====================================================================================================");
                        printf("[%03d] Nama Lengkap: %s\n", PeekSI, SIList.FullName);
                        printf("... Nama Industri: %s\n", SIList.IndustryName);
                        puts("====================================================================================================");
                        for (int SI = 0; SI < MaxStocks; SI++) {
                            strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * (PeekSI - 1)) + (SI_PRODUCT_NO_1 + SI))));
                            CheckStock[strlen(CheckStock) - 1] = '\0';

                            if (strchr(CheckStock, '-') != NULL) {
                                if (PeekStockID == (SI + 1)) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }
                                else { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }

                            } else {
                                strcpy(ProductName, CheckStock);
                                strtok_r(ProductName, ",", &ProductStock);
                                strtok_r(ProductStock, ",", &ProductPrice);
                                ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                                AvailableStocks++;
                                if (PeekStockID == (SI + 1)) {
                                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                    strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                                } else {
                                    printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                                    printf("...  Stok Produk: %s\n", ProductStock);
                                    printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                                } if (SI != (MaxStocks - 1)) { puts(""); }
                            }
                        } puts("====================================================================================================");

                        puts("");
                        puts("Mohon maaf, untuk saat ini slot produk hasil Sektor Industri yang bersangkutan MASIH kosong...");
                        puts("... Silakan untuk memilih produk lainnya hasil produksi dari yang bersangkutan!");
                        puts("");
                        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                        system("pause"); break;
                    }
                }

            } else if (PeekStockID == 0) {
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); UMMFeature04();
            } else { CheckInvalidInput = true; UMMFeature04();  }
        }
    } else if (PeekSI == 0) {
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); UserMainMenu();
    } else { CheckInvalidInput = true; UMMFeature04();  }
}

void ClientMainMenu(void) {
    int CMMOption = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        ClientMainMenu();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
    printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);

    puts("");
    puts("~ Apa yang ingin Anda kerjakan pada kesempatan kali ini? ~");
    puts("[1] Lihat Pendapatan Sektor Industri");
    puts("[2] Pengaturan Barang Produksi");
    puts("[3] Pengaturan Kerja Sama dengan Kepala Daerah");
    puts("[0] Keluar... (Log Out)");

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
    char CurrentFileSI[BUFSIZE07], TotalSavings[BUFSIZE07], SISSPositive[BUFSIZE07];
    
    ClearScreen();
    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
    printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
    puts("\nMenu: [1] Lihat Pendapatan Sektor Industri");

    snprintf(CurrentFileSI, sizeof(CurrentFileSI) + 12, "SI - %s.txt", SIFullName);
    snprintf(SISSPositive, sizeof(SISSPositive) + 21, "%s > [+]", CurrentFileSI);

    strcpy(TotalSavings, ReadLine(CurrentFileSI, AVAILABLE_DATA));
    TotalSavings[strlen(TotalSavings) - 1] = '\0';

    puts("");
    puts("Berikut adalah data akumulasi perekonomian dana industri dari yang bersangkutan:");
    puts("====================================================================================================");
    printf("Dana Perekonomian Total: Rp%'lld.00\n", atoll(TotalSavings)); puts("");
    puts("Pemasukkan (Incomes): ");
    SearchAll(CurrentFileSI, false, 0, SISSPositive); puts("");
    puts("Pengeluaran (Expenses): TIDAK ADA PENGELUARAN BAGI SEKTOR INDUSTRI");
    puts("====================================================================================================");

    puts("");
    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        CMMFeature02();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
    printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
    puts("\nMenu: [2] Pengaturan Barang Produksi");

    puts("");
    puts("====================================================================================================");
    for (int SI = 0; SI < MaxStocks; SI++) {
        strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + SI))));
        CheckStock[strlen(CheckStock) - 1] = '\0';

        if (strcmp(CheckStock, "-, -, -") == 0) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); }
        else {
            strcpy(ProductName, CheckStock);
            strtok_r(ProductName, ",", &ProductStock);
            strtok_r(ProductStock, ",", &ProductPrice);
            ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

            AvailableStocks++; InStocks[SI] = 1;
            printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
            printf("...  Stok Produk: %s\n", ProductStock);
            printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
            if (SI != (MaxStocks - 1)) { puts(""); }
        }
    } puts("====================================================================================================");
    
    ProductName[0] = 0; ProductStock = ""; ProductPrice = "";

    puts("");
    if (AvailableStocks >= 0 && AvailableStocks < 3) {
        printf("Tersedia %d dari %d stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts("... TAMBAHKAN produk hasil industri baru?\n");
        puts("(ketik angka bebas dari [1] hingga [5] untuk dilakukan pengisian data produk baru)");

    } else if (AvailableStocks >= 3 && AvailableStocks < 5) {
        printf("Tersedia %d dari %d stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts("... TAMBAHKAN produk hasil industri baru atau PERBAHARUI data produk yang sudah ada?\n");
        puts("(ketik angka penomoran yang sesuai dengan yang telah berlaku seperti di atas)");
    
    } else if (AvailableStocks == 5) {
        printf("Tersedia %d dari %d stok produk industri seperti pada di atas.\n", AvailableStocks, MaxStocks);
        puts("... HAPUSKAN produk hasil industri lama atau PERBAHARUI data produk yang sudah ada?\n");
        puts("(ketik angka penomoran yang sesuai dengan yang telah berlaku seperti di atas)");
    }

    puts("(jika tidak, silakan ketik [0] untuk kembali ke menu sebelumnya)");
    AcceptInputOption("> Pilihan Anda: ", PeekStockID);

    if (PeekStockID > 0 && PeekStockID < 6) {
        while (true) {
            ClearScreen();

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
            printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
            puts("\nMenu: [2] Pengaturan Barang Produksi");

            puts("");
            puts("====================================================================================================");
            for (int SI = 0; SI < MaxStocks; SI++) {
                strcpy(CheckStock, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + SI))));
                CheckStock[strlen(CheckStock) - 1] = '\0';

                if (strchr(CheckStock, '-') != NULL) {
                    if (PeekStockID == (SI + 1)) { printf("[%d]: Stok produk industri masih kosong\n", (SI + 1)); break; }
                } else {
                    strcpy(ProductName, CheckStock);
                    strtok_r(ProductName, ",", &ProductStock);
                    strtok_r(ProductStock, ",", &ProductPrice);
                    ProductStock = TrimWhiteSpaces(ProductStock); ProductPrice = TrimWhiteSpaces(ProductPrice);

                    AvailableStocks++;
                    if (PeekStockID == (SI + 1)) {
                        printf("[%d]: Nama Produk: %s\n", (SI + 1), ProductName);
                        printf("...  Stok Produk: %s\n", ProductStock);
                        printf("...  Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
                        strcpy(DisplayProductName, ProductName); strcpy(DisplayProductStock, ProductStock); strcpy(DisplayProductPrice, ProductPrice);
                        break;
                    }
                }
            } puts("====================================================================================================");
            
            ProductName[0] = 0; ProductStock = ""; ProductPrice = "";
            
            puts("");
            if (InStocks[PeekStockID - 1] == 1) {
                puts("CATATAN:  Biarkan sesi input kosong apabila data yang bersangkutan TIDAK ingin diubah!");
                puts("...       Jika produck yang bersnagkutan ingin DIHAPUS, maka sertakan tanda '-' di setiap sesi input");
                puts("...       berikut (tanpa tanda petiknya) agar produk tersebut berhasil dihapuskan...");
                puts("TAMBAHAN: Perlu diingat hanya sertakan SATU TANDA '-' saja, jika tidak akan dianggap INVALID secara keseluruhan!");
                
                puts("");
                puts("[Texts]: Input harus berupa teks");
                puts("[>=  N]: Bilangan bulat positif, N termasuk");

                puts("");
                AcceptInputText("[ Texts ] Nama produk BARU yang bersangkutan: ", NewProductName);
                AcceptInputText("[>=    1] Stok total produk BARU yang bersangkutan: ", NewProductStock);
                AcceptInputText("[>= 1000] Harga per produk BARU yang bersangkutan: ", NewProductPrice);
                NewProductName[strlen(NewProductName) - 1] = '\0'; NewProductStock[strlen(NewProductStock) - 1] = '\0'; NewProductPrice[strlen(NewProductPrice) - 1] = '\0';

                if (strcmp(NewProductName, "-") == 0 && strcmp(NewProductStock, "-") == 0 && strcmp(NewProductPrice, "-") == 0) {
                    snprintf(FinalWrittenProduct, sizeof(FinalWrittenProduct), "-, -, -");
                    OverWriteStringAtLine(Client_SektorIndustri, FinalWrittenProduct, 0, (((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + (PeekStockID - 1))));

                    puts("");
                    puts("Penghapusan data produk yang bersangkutan TELAH BERHASIL!");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause"); CMMFeature02();
                
                } else if (strlen(NewProductName) > 1 && strchr(NewProductName, '-')) {
                    puts("");
                    puts("ERROR: Maaf, nama produk yang mengandung tanga '-' kami anggap TIDAK VALID dikarekanakan SINTAKS penggunaan");
                    puts("...    tanda '-' hanya untuk PENGHAPUSAN data produk yang bersangkutan, jadi mohon pengertiannya!");
                    puts(":: Anda akan dibawa kembali ke pengisian data produk industri...");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");

                } else if (strcmp(NewProductName, "-") != 0 && strcmp(NewProductStock, "-") != 0 && strcmp(NewProductPrice, "-") != 0) {
                    if (strlen(NewProductName) == 0)  { strcpy(NewProductName, DisplayProductName);   }
                    if (strlen(NewProductStock) == 0) { strcpy(NewProductStock, DisplayProductStock); }
                    if (strlen(NewProductPrice) == 0) { strcpy(NewProductPrice, DisplayProductPrice); }
                    
                    if (atoll(NewProductStock) < 1LL || strchr(NewProductStock, '.') != NULL) {
                        puts("");
                        puts("PERHATIAN: Nilai stok total produk harus LEBIH DARI SAMA DENGAN 1!\n:: Melakukan penyetelan ulang ke nomina 1 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductStock, "1");
                    } if (atoll(NewProductPrice) < 1000LL || strchr(NewProductPrice, '.') != NULL) {
                        puts("");
                        puts("PERHATIAN: Nilai harga per produk harus LEBIH DARI SAMA DENGAN 1000!\n:: Melakukan penyetelan ulang ke nomina 1000 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductPrice, "1000");
                    }

                    snprintf(FinalWrittenProduct, (sizeof(FinalWrittenProduct) * 3) + 4, "%s, %s, %s", NewProductName, NewProductStock, NewProductPrice);
                    OverWriteStringAtLine(Client_SektorIndustri, FinalWrittenProduct, 0, (((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + (PeekStockID - 1))));

                    puts("");
                    puts("Data produk industri yang bersangkutan telah diperbaharui!");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    CMMFeature02();
                
                } else {
                    puts("");
                    puts("ERROR: Sekali lagi, dimohon jika ingin dilakukan penghapusan data produk, pastikan SINTAKS INPUT-NYA TELAH SESUAI");
                    puts("...    dengan yang diminta agar tidak terjadi kesalahan input data, jadi mohon pengertiannya!");
                    puts(":: Anda akan dibawa kembali ke pengisian data produk industri...");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                }

            } else if (InStocks[PeekStockID - 1] == 0) {
                puts("PERHATIKAN apabila terdapat sesi input yang kosong, maka Anda harus mengelola data KEMBALI DARI SEMULA!");
                puts("... Mohon perhatiannya, terutama dalam pengisian Nama Produk, dan teruntuk Stok beserta Harga Produk akan");
                puts("... ada penyetelannya sendiri ke nomina default mereka masing-masing...");
                puts("[Texts]: Input harus berupa teks");
                puts("[>= N]: Bilangan bulat positif; Angka N termasuk");

                puts("");
                AcceptInputText("[ Texts ] Nama Produk: ", NewProductName);
                AcceptInputText("[>=    1] Stok Total Produk: ", NewProductStock);
                AcceptInputText("[>= 1000] Harga per Produk: ", NewProductPrice);
                NewProductName[strlen(NewProductName) - 1] = '\0'; NewProductStock[strlen(NewProductStock) - 1] = '\0'; NewProductPrice[strlen(NewProductPrice) - 1] = '\0';

                if (strlen(NewProductName) == 0) {
                    puts("");
                    puts("ERROR: Sekali lagi, dimohon untuk tidak mengosongkan sesi input Nama Produk yang bersangkutan dikarenakan");
                    puts("...    saat ini Anda tengah mengisi data baru, jadi mohon pengertiannya!");
                    puts(":: Anda akan dibawa kembali ke pengisian data produk industri...");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");

                } else if ((strcmp(NewProductName, "-") == 0 && strcmp(NewProductStock, "-") == 0 && strcmp(NewProductPrice, "-") == 0)) {
                    puts("");
                    puts("ERROR: Maaf, kami tidak menerima PENGHAPUSAN data produk industri apabila data yang bersangkutan masih");
                    puts("...    kosong dikarenakan belum ada diisi oleh apapun dari pihak Anda, jadi mohon pengertiannya!");
                    puts(":: Anda akan dibawa kembali ke pengisian data produk industri...");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                 
                } else if (strlen(NewProductName) > 1 && strchr(NewProductName, '-')) {
                    puts("");
                    puts("ERROR: Maaf, nama produk yang mengandung tanga '-' kami anggap TIDAK VALID dikarekanakan SINTAKS penggunaan");
                    puts("...    tanda '-' hanya untuk PENGHAPUSAN data produk yang bersangkutan, jadi mohon pengertiannya!");
                    puts(":: Anda akan dibawa kembali ke pengisian data produk industri...");
                    
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");

                } else { 
                    if (atoll(NewProductStock) < 1LL || strchr(NewProductStock, '.') != NULL) {
                        puts("");
                        puts("PERHATIAN: Nilai stok total produk harus LEBIH DARI SAMA DENGAN 1!\n:: Melakukan penyetelan ulang ke nomina 1 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductStock, "1");
                    } if (atoll(NewProductPrice) < 1000LL || strchr(NewProductPrice, '.') != NULL) {
                        puts("");
                        puts("PERHATIAN: Nilai harga per produk harus LEBIH DARI SAMA DENGAN 1000!\n:: Melakukan penyetelan ulang ke nomina 1000 (Anda dapat menyetel ulang kembali nantinya)...");
                        strcpy(NewProductPrice, "1000");
                    }

                    snprintf(FinalWrittenProduct, (sizeof(FinalWrittenProduct) * 3) + 4, "%s, %s, %s", NewProductName, NewProductStock, NewProductPrice);
                    OverWriteStringAtLine(Client_SektorIndustri, FinalWrittenProduct, 0, (((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + (PeekStockID - 1))));

                    puts("");
                    puts("Data produk industri BARU telah ditambahkan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    CMMFeature02();
                }
            }
        }

    } else if (PeekStockID == 0) {
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); ClientMainMenu();
    } else { CheckInvalidInput = true; CMMFeature02(); }
}

void CMMFeature03(void) {
    KepalaDaerah KDList = { 0 };
    FILE *AccessKDSavings, *AccessSISavings;

    char DisplayKDRequests[BUFSIZE10][BUFSIZE07] = { 0 };
    char UpdateStatus;
    char ProductName[BUFSIZE07] = { 0 }, *ProductStock, *ProductPrice, DisplayProductName[BUFSIZE07] = { 0 }, *DisplayProductStock, *DisplayProductPrice;
    char CurrentKDFile[BUFSIZE07] = { 0 }, FinalKDSavings[BUFSIZE07] = { 0 };
    char CurrentSIFile[BUFSIZE07] = { 0 }, FinalSISavings[BUFSIZE07] = { 0 };
    int GetStockID = 0, RecentStatus = 0;
    int AvailableReqs = 0, AvailableKDs = 0, PeekKD = 0, MaxReq = 0, SaveKDID = 0;

    ClearScreen();
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");

        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause");
        CheckInvalidInput = false;
        CMMFeature03();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
    printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
    puts("\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah");

    AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
    AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));
    
    puts("");
    puts("Berikut adalah data pengajuan kerja sama dari pelbagai Kepala Daerah dengan yang bersangkutan...");
    
    puts("====================================================================================================");
    for (int REQ = 0; REQ < AvailableReqs; REQ++) {
        strcpy(Belanja.Requester, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_HD_IDENTITY));
        strcpy(Belanja.Accepter, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_CS_IDENTITY));
        strcpy(Belanja.ProductInDemand, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_BOUGHT_PRODUCT));
        Belanja.Status = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * REQ) + CS_SELLING_STATUS));
        Belanja.Requester[strlen(Belanja.Requester) - 1] = '\0'; Belanja.Accepter[strlen(Belanja.Accepter) - 1] = '\0'; Belanja.ProductInDemand[strlen(Belanja.ProductInDemand) - 1] = '\0';
        
        for (int KD = 0; KD < AvailableKDs; KD++) {
            if (strstr(Belanja.Accepter, SIFullName) != NULL && strstr(Belanja.Accepter, SIIndustryName)) {
                MaxReq++;

                strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
                strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
                strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
                KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';
                RecentStatus = atoi(ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_SI_BOUGHT_PRODUCT_STATUS));

                if (Belanja.Status == 0 && strstr(Belanja.Requester, KDList.FullName) != NULL && strstr(Belanja.Requester, KDList.JobTitle) != NULL && strstr(Belanja.Requester, KDList.HeadRegion) != NULL) {
                    printf("[%03d] Nama Lengkap: %s\n", (REQ + 1), KDList.FullName);
                    printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                    if      (RecentStatus == 0)  { puts("... Status Permintaan: -"); }
                    else if (RecentStatus == 1)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                    else if (RecentStatus == 2)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                    else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }
                    
                    strcpy(DisplayKDRequests[REQ], Belanja.Requester);

                } else if ((Belanja.Status == 1 || Belanja.Status == -1) && strstr(Belanja.Requester, KDList.FullName) != NULL && strstr(Belanja.Requester, KDList.JobTitle) != NULL && strstr(Belanja.Requester, KDList.HeadRegion) != NULL) {
                    printf("[%03d] Nama Lengkap: %s\n", (REQ + 1), KDList.FullName);
                    printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                    if      (Belanja.Status == 1)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                    else if (Belanja.Status == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }

                    strcpy(DisplayKDRequests[REQ], Belanja.Requester);
                
                } else { continue; }
            }
        } if (MaxReq != 0) { if (REQ + 1 != AvailableReqs) { puts(""); } }
    } 
    
    if (MaxReq != 0) { puts("===================================================================================================="); }
    else             { puts("Data pengajuan dari Kepala Daerah kosong!"); puts("===================================================================================================="); }
    
    if (MaxReq > 0) {
        puts("");
        puts("Kepada siapa pengajuan kerja sama dari Kepala Daerah pada data di atas yang ingin Anda KELOLA lebih lanjut?");
        puts("(kondisi input disesuaikan sesuai penomoran Kepala Daerah di atas)");
        puts("(jika ingin kembali ke menu sebelumnya, ketik 0 pada input di bawah)");
        AcceptInputOption("> Pilihan Anda: ", PeekKD);

        if (PeekKD > 0 && PeekKD <= AvailableReqs) {
            ClearScreen();
            
            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
            printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
            puts("\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah");

            AvailableKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));
            AvailableReqs = atoi(ReadLine(UserCartStore_Keranjang, AVAILABLE_DATA));

            puts("");
            puts("Berikut adalah data pengajuan kerja sama dari pelbagai Kepala Daerah dengan yang bersangkutan...");
            
            puts("====================================================================================================");
            for (int KD = 0; KD < AvailableKDs; KD++) {
                strcpy(KDList.FullName, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_FULLNAME));
                strcpy(KDList.JobTitle, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DEPARTMENT));
                strcpy(KDList.HeadRegion, ReadLine(User_KepalaDaerah, ((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME));
                KDList.FullName[strlen(KDList.FullName) - 1] = '\0'; KDList.JobTitle[strlen(KDList.JobTitle) - 1] = '\0'; KDList.HeadRegion[strlen(KDList.HeadRegion) - 1] = '\0';

                if (strstr(DisplayKDRequests[PeekKD - 1], KDList.FullName) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.JobTitle) != NULL && strstr(DisplayKDRequests[PeekKD - 1], KDList.HeadRegion) != NULL) {
                    printf("[%03d] Nama Lengkap: %s\n", (KD + 1), KDList.FullName);
                    printf("... Jabatan/Daerah: %s %s\n", KDList.JobTitle, KDList.HeadRegion);

                    RecentStatus = atoi(ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekKD - 1)) + CS_SELLING_STATUS));
                    if      (RecentStatus == 0)  { puts("... Status Permintaan: SEDANG DIPROSES"); }
                    else if (RecentStatus == 1)  { puts("... Status Permintaan: PENGAJUAN DITERIMA"); }
                    else if (RecentStatus == -1) { puts("... Status Permintaan: PENGAJUAN DITOLAK"); }

                    strcpy(DisplayProductName, ReadLine(UserCartStore_Keranjang, ((OFFSET_CS + 1) * (PeekKD - 1)) + CS_BOUGHT_PRODUCT));
                    DisplayProductName[strlen(DisplayProductName) - 1] = '\0';
                    strtok_r(DisplayProductName, ",", &DisplayProductStock); DisplayProductStock = TrimWhiteSpaces(DisplayProductStock);
                    strtok_r(DisplayProductStock, ",", &DisplayProductPrice); DisplayProductPrice = TrimWhiteSpaces(DisplayProductPrice);
                    
                    puts("");
                    printf("Daftar Pesanan:\n... 1. Nama Pesanan Produk: %s\n... 2. Stok Pesanan Produk: %s\n... 3. Harga Total Pesanan Produk: Rp%'lld.00\n", DisplayProductName, DisplayProductStock, atoll(DisplayProductPrice));
                    SaveKDID = KD;
                    break;
                }
            }

            int MaxStocks = 5;
            for (int ID = 0; ID < MaxStocks; ID++) {
                strcpy(ProductName, ReadLine(Client_SektorIndustri, ((OFFSET_HD + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + ID)));
                ProductName[strlen(ProductName) - 1] = '\0';

                if (strstr(ProductName, DisplayProductName) != NULL) {
                    strtok_r(ProductName, ",", &ProductStock); ProductStock = TrimWhiteSpaces(ProductStock);
                    strtok_r(ProductStock, ",", &ProductPrice); ProductPrice = TrimWhiteSpaces(ProductPrice);
                    GetStockID = ID;
                    break;
                }
            }

            if (RecentStatus == 1) {
                puts("====================================================================================================\n");
                puts("Status Pengajuan: PENGAJUAN DITERIMA");
                puts(":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                puts(":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();

            } else if (RecentStatus == -1) {
                puts("====================================================================================================\n");
                puts("Status Pengajuan: PENGAJUAN DITOLAK");
                puts(":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan");
                puts(":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();
            
            } else if (RecentStatus == 0) {
                puts("====================================================================================================");
                puts("Produk Sektor Industri yang bersangkutan:");

                printf("... Nama Produk: %s\n", ProductName);
                if      (RecentStatus == 0)  { printf("... Stok Produk: %lld >> %lld\n", atoll(ProductStock), (atoll(ProductStock) - atoll(DisplayProductStock))); }
                else if (RecentStatus == 1)  { printf("... Stok Produk: %lld >> %lld (-%lld)\n", atoll(ProductStock) + atoll(DisplayProductStock), atoll(ProductStock), atoll(DisplayProductStock)); }
                else if (RecentStatus == -1) { printf("... Stok Produk: %lld >> %lld (-%d)\n", atoll(ProductStock), atoll(ProductStock), 0); }
                printf("... Harga Produk (per item): Rp%'lld.00\n", atoll(ProductPrice));
            } puts("====================================================================================================");

            if ((atoll(ProductStock) - atoll(DisplayProductStock)) < 0) {
                puts("");
                puts("Maaf, saat ini stok produk Anda yang dipesan oleh Kepala Daerah yang bersangkutan tidak memenuhi!");
                puts("Mohon diperhatikan kembali lebih lanjut mengenai ketersediaan stok produk industri...");
                puts("... Anda akan di bawa kembali ke menu sebelumnya...");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();
            }

            puts("");
            puts("Saat ini Kepala Daerah yang bersangkutan tengah dalam masa pemrosesan pengajuan kerja sama dari pihak Anda.");
            puts("... Berdasarkan pemesanan yang dibuatnya di atas, apakah Anda yakin untuk MENERIMA pengajuan dari beliau, atau harus MENOLAKNYA?");
            puts("... Tidak akan ada pengeluaran yang dihasilkan selama proses ini berlangsung!");
            
            puts("");
            puts("(sertakan Y atau y untuk menyetujui pengajuan, dan N atau n untuk menolak pengajuan)");
            puts("(sertakan Q atau q untuk kembali ke menu sebelumnya)");
            AcceptCharInput("> Pilihan Anda: ", UpdateStatus);

            if (UpdateStatus == 'Y' || UpdateStatus == 'y') {
                ClearScreen();

                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
                printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
                puts("\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah");

                OverWriteStringAtLine(User_KepalaDaerah, "2", 0, ((OFFSET_HD + 1) * SaveKDID) + HD_SI_BOUGHT_PRODUCT_STATUS);
                OverWriteStringAtLine(UserCartStore_Keranjang, "1", 0, ((OFFSET_CS + 1) * (PeekKD - 1)) + CS_SELLING_STATUS);

                snprintf(CurrentKDFile, sizeof(CurrentKDFile) + 12, "KD - %s.txt", KDList.FullName);
                AccessKDSavings = fopen(CurrentKDFile, "a");
                fprintf(AccessKDSavings, "[-] Rp%'lld.00: Pembelian produk (%s: %s) item, dari Yth. %s, %s\n", atoll(DisplayProductPrice), DisplayProductName, DisplayProductStock, SIFullName, SIIndustryName);
                fclose(AccessKDSavings);
                snprintf(FinalKDSavings, sizeof(FinalKDSavings), "%lld", atoll(ReadLine(CurrentKDFile, AVAILABLE_DATA)) - atoll(DisplayProductPrice));
                OverWriteStringAtLine(CurrentKDFile, FinalKDSavings, 0, AVAILABLE_DATA);
                CurrentKDFile[0] = 0;

                snprintf(CurrentSIFile, sizeof(CurrentSIFile) + 12, "SI - %s.txt", SIFullName);
                AccessSISavings = fopen(CurrentSIFile, "a");
                fprintf(AccessSISavings, "[+] Rp%'lld.00: Penjualan produk (%s: %s) item, kepada Yth. %s, %s %s\n", atoll(DisplayProductPrice), DisplayProductName, DisplayProductStock, KDList.FullName, KDList.JobTitle, KDList.HeadRegion);
                fclose(AccessSISavings);
                snprintf(FinalSISavings, sizeof(FinalSISavings), "%lld", atoll(ReadLine(CurrentSIFile, AVAILABLE_DATA)) + atoll(DisplayProductPrice));
                OverWriteStringAtLine(CurrentSIFile, FinalSISavings, 0, AVAILABLE_DATA);
                CurrentSIFile[0] = 0;

                char GetCurrentStock[BUFSIZE07] = { 0 }, SetCurrentStock[BUFSIZE07] = { 0 };
                strcpy(GetCurrentStock, ReadLine(Client_SektorIndustri, ((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + GetStockID)));
                GetCurrentStock[strlen(GetCurrentStock) - 1] = '\0';
                strcpy(ProductName, GetCurrentStock);
                strtok_r(ProductName, ",", &ProductStock); ProductStock = TrimWhiteSpaces(ProductStock);
                strtok_r(ProductStock, ",", &ProductPrice); ProductPrice = TrimWhiteSpaces(ProductPrice);
                snprintf(SetCurrentStock, (sizeof(SetCurrentStock) * 3) + 13, "%s, %lld, %s", ProductName, atoll(ProductStock) - atoll(DisplayProductStock), ProductPrice);
                OverWriteStringAtLine(Client_SektorIndustri, SetCurrentStock, 0, ((OFFSET_SI + 1) * SILoggedIn) + (SI_PRODUCT_NO_1 + GetStockID));
        
                puts("");
                puts("Status Pengajuan: PENGAJUAN DITERIMA");
                puts(":: Selamat, Anda telah menyetujui pengajuan kerja sama dari Kepala Daerah yang bersangkutan...");
                puts(":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();

            } else if (UpdateStatus == 'N' || UpdateStatus == 'n') {
                ClearScreen();

                puts("Selamat Datang di aplikasi: D'Wakanda!");
                puts("Anda tengah masuk sebagai: Client :: Sektor Industri.");
                printf("... Profil Sektor Industri: %s, %s.\n", SIFullName, SIIndustryName);
                puts("\nMenu: [3] Pengaturan Kerja Sama dengan Kepala Daerah");

                OverWriteStringAtLine(User_KepalaDaerah, "-1", 0, ((OFFSET_HD + 1) * SaveKDID) + HD_SI_BOUGHT_PRODUCT_STATUS);
                OverWriteStringAtLine(UserCartStore_Keranjang, "-1", 0, ((OFFSET_CS + 1) * (PeekKD - 1)) + CS_SELLING_STATUS);

                puts("");
                puts("Status Pengajuan: PENGAJUAN DITOLAK");
                puts(":: Maaf, Anda telah menolak pengajuan kerja sama dari Kepala Daerah yang bersangkutan");
                puts(":: Anda dapat menunggu ajakan pengajuan kembali darinya pada saat-saat berikutnya!");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();
            
            } else if (UpdateStatus == 'Q' || UpdateStatus == 'q') {
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause"); CMMFeature03();
            }

        } else if (PeekKD == 0) {
            puts("");
            puts("(tekan tombol [ENTER] untuk melanjutkan...)");
            system("pause");
            ClientMainMenu();

        } else { CheckInvalidInput = true; CMMFeature03(); }
    
    } else {
        puts("");
        puts("Saat ini belum ada Kepala Daerah yang ingin mengajukan pemesanan produk kerja sama dengan pihak Anda...");
        puts("... Anda dapat menunggu dan/atau memantau secara berkala apakah ada pemesanan yang dilakukan ke depannya!");
        puts("... Dipersilakan untuk kembali ke menu semula...");
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); ClientMainMenu();
    }
}

void AdminLobbyMenu(void) {
    ClearScreen();

    if (CheckInvalidInput) {
        puts("ERROR: Nama pengguna dan/atau kata sandi salah!");
        puts("... Silahkan untuk diperiksa kembali (tanpa batas pengecekan)!");
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; AdminLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda berada dalam lobi: Admin :: Kementerian Keuangan.");

    puts("");
    puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
    puts("... 1. Nama Pengguna (maks. 128 karakter)");
    puts("... 2. Kata Sandi    (8-16 karakter)");

    puts("");
    AcceptInputText("Nama Pengguna: ", AdminSignIn.SignInUsername)
    AcceptInputText("Kata Sandi:    ", AdminSignIn.SignInPassword)

    if (strcmp(AdminSignIn.SignInUsername, ReadLine(Admin_Kemenkeu, MF_USERNAME)) == 0 && \
        strcmp(AdminSignIn.SignInPassword, ReadLine(Admin_Kemenkeu, MF_PASSWORD)) == 0) {
            
            AdminMainMenu();
    
    } else {
        CheckInvalidInput = true;
        AdminLobbyMenu();
    }
}

void UserLobbyMenu(void) {
    ClearScreen();

    int RegisteredKDs = 0;
    if (CheckInvalidInput) {
        if (RSOption == 0) {
            puts("ERROR: Input yang diterima tidaklah valid!");
            puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");
        } else if (RSOption == 2) {
            puts("ERROR: NIK (Nomor Induk Kewarganegaraan) dan/atau kata sandi salah!");
            puts("... Silahkan untuk diperiksa kembali (tidak ada batasan pengecekan)!");
        }
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; UserLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    if (RSOption == 0) {
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda berada dalam lobi: User :: Kepala Daerah.");

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

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda berada dalam lobi: User :: Kepala Daerah.");

            puts("");
            puts("Silakan untuk memasukkan TUJUH (7) kredensial baru Anda seperti berikut:");
            if (CountRegists >= 2) printf("... 1. Nama Lengkap:         %s\n", KDSignIn.FullName);
            if (CountRegists >= 3) printf("... 2. NIK:                  %s\n", KDSignIn.NIK);
            if (CountRegists >= 4) printf("... 3. E-mail:               %s\n", KDSignIn.Email);
            if (CountRegists >= 5) { printf("... 4. Kata Sandi:           "); for (size_t i = 0; i < strlen(KDSignIn.Password); i++) { printf("*"); } printf("\n"); }
            if (CountRegists >= 6) printf("... 5. Tempat/Tanggal Lahir: %s\n", KDSignIn.BirthPlaceDate);
            if (CountRegists >= 7) printf("... 6. Jabatan:              %s\n", KDSignIn.JobTitle);
            if (CountRegists >= 8) printf("... 7. Daerah Perwakilan:    %s\n", KDSignIn.HeadRegion);
            if (CountRegists < 2)  printf("... 1. Nama Lengkap:         (maks. 128 karakter)\n");
            if (CountRegists < 3)  printf("... 2. NIK:                  (wajib 16 digit)\n");
            if (CountRegists < 4)  printf("... 3. E-mail:               (memenuhi sintaks e-mail sesungguhnya)\n");
            if (CountRegists < 5)  printf("... 4. Kata Sandi:           (8-16 karakter)\n");
            if (CountRegists < 6)  printf("... 5. Tempat/Tanggal Lahir: (format: TEMPAT, DD/MM/YYYY)\n");
            if (CountRegists < 7)  printf("... 6. Jabatan:              (golongan gubernur/bupati/wali kota)\n");
            if (CountRegists < 8)  printf("... 7. Daerah Perwakilan:    (nama daerah dari kepala daerah)\n");
            
            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Lengkap: ", KDSignIn.FullName);
                if (strlen(KDSignIn.FullName) < 2 || strlen(KDSignIn.FullName) > 128) {
                    puts("");
                    puts("ERROR: Data nama lengkap melebihi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.FullName[strlen(KDSignIn.FullName) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("NIK: ", KDSignIn.NIK);
                if (strlen(KDSignIn.NIK) != 17) {
                    puts("");
                    puts("ERROR: Data NIK belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.NIK[strlen(KDSignIn.NIK) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 3) {
                AcceptInputText("E-mail: ", KDSignIn.Email);
                if (strchr(KDSignIn.Email, '@') == NULL || strchr(KDSignIn.Email, '.') == NULL || strchr(KDSignIn.Email, ' ') != NULL || strlen(KDSignIn.Email) > 128) {
                    puts("");
                    puts("ERROR: Data e-mail belum sesuai dengan sintaks yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.Email[strlen(KDSignIn.Email) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 4) {
                AcceptInputText("Kata Sandi: ", KDSignIn.Password);
                if (strlen(KDSignIn.Password) < 9 || strlen(KDSignIn.Password) > 17) {
                    puts("");
                    puts("ERROR: Data kata sandi belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.Password[strlen(KDSignIn.Password) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 5) {
                AcceptInputText("Tempat/Tanggal Lahir: ", KDSignIn.BirthPlaceDate);
                if (strchr(KDSignIn.BirthPlaceDate, ',') == NULL || strchr(KDSignIn.BirthPlaceDate, ' ') == NULL || strlen(KDSignIn.BirthPlaceDate) > 128) {
                    puts("");
                    puts("ERROR: Data tempat/tanggal lahir belum memenuhi kriteria yang diminta!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.BirthPlaceDate[strlen(KDSignIn.BirthPlaceDate) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 6) {
                AcceptInputText("Jabatan (Gubernur/Bupati/Wali Kota): ", KDSignIn.JobTitle);
                if (strcmp(StringCapitalize(KDSignIn.JobTitle), "Gubernur\n") != 0 && strcmp(StringCapitalize(KDSignIn.JobTitle), "Bupati\n") != 0 && strcmp(StringCapitalize(KDSignIn.JobTitle), "Wali kota\n") != 0) {
                    puts("");
                    puts("ERROR: Data golongan jabatan belum sesuai dengan pilihan yang tersedia!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
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
                    puts("ERROR: Data kepala wilayah/daerah terlalu singkat/panjang!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; KDSignIn.HeadRegion[strlen(KDSignIn.HeadRegion) - 1] = '\0'; UserLobbyMenu(); }    
            }

            if (CountRegists == 8) {
                ClearScreen();

                puts("SUCCESS: Kepala daerah baru telah berhasil didaftarkan!");
                puts("INFO: Silakan untuk melanjutkan interaksi berikut dengan masuk ke menu sign-in/login... .");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");

                WritePublicKepalaDaerah();

                CountRegists = 1; RSOption = 2;
                KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                UserLobbyMenu();
            }

        } else if (RSOption == 2) {
            if (access(User_KepalaDaerah, F_OK) != 0) {
                ClearScreen();

                puts("ERROR: Belum terdapat kepala daerah yang terdaftarkan!");
                puts("... Silahkan untuk masuk ke menu registrasi kepala daerah terlebih dahulu!");

                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");
                
                CountRegists = 1; RSOption = 1;
                KDSignIn.FullName[0] = 0; KDSignIn.NIK[0] = 0; KDSignIn.Email[0] = 0; KDSignIn.Password[0] = 0;
                KDSignIn.BirthPlaceDate[0] = 0; KDSignIn.JobTitle[0] = 0; KDSignIn.HeadRegion[0] = 0;
                UserLobbyMenu();
            }

            ClearScreen();
            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda berada dalam lobi: User :: Kepala Daerah.");

            puts("");
            puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
            if (CountRegists >= 2) printf("... 1. NIK:        %s\n", KDSignIn.NIK);
            if (CountRegists >= 3) { printf("... 2. Kata Sandi: "); for (size_t i = 0; i < strlen(KDSignIn.Password); i++) { printf("*"); } printf("\n"); }
            if (CountRegists < 2)  printf("... 1. NIK:        (wajib 16 digit)\n");
            if (CountRegists < 3)  printf("... 2. Kata Sandi: (8-16 karakter)\n");

            puts("");
            if (CountRegists == 1) {
                AcceptInputText("NIK: ", KD_SignInNIK);
                if (strlen(KD_SignInNIK) != 17) {
                    puts("");
                    puts("ERROR: Data NIK belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; strncpy(KDSignIn.NIK, KD_SignInNIK, 32); KDSignIn.NIK[strlen(KDSignIn.NIK) - 1] = '\0'; UserLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Kata Sandi: ", KD_SignInPassword);
                if (strlen(KD_SignInPassword) < 9 || strlen(KD_SignInPassword) > 17) {
                    puts("");
                    puts("ERROR: Data kata sandi belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    UserLobbyMenu();
                } else { CountRegists++; strncpy(KDSignIn.Password, KD_SignInPassword, 32); KDSignIn.Password[strlen(KDSignIn.Password) - 1] = '\0'; UserLobbyMenu(); }
            }

            if (CountRegists == 3) {
                RegisteredKDs = atoi(ReadLine(User_KepalaDaerah, AVAILABLE_DATA));

                for (int KD = 0; KD < RegisteredKDs; KD++) {
                    if (strcmp(KD_SignInNIK, ReadLine(User_KepalaDaerah, (((OFFSET_HD + 1) * KD) + HD_CIN))) == 0 && \
                        strcmp(KD_SignInPassword, ReadLine(User_KepalaDaerah, (((OFFSET_HD + 1) * KD) + HD_PASSWORD))) == 0) {
                            
                            strncpy(KDFullName, ReadLine(User_KepalaDaerah, (((OFFSET_HD + 1) * KD) + HD_FULLNAME)), BUFSIZE07);
                            strncpy(KDJobTitle, ReadLine(User_KepalaDaerah, (((OFFSET_HD + 1) * KD) + HD_DEPARTMENT)), BUFSIZE07);
                            strncpy(KDHeadRegion, ReadLine(User_KepalaDaerah, (((OFFSET_HD + 1) * KD) + HD_DISTRICT_NAME)), BUFSIZE07);
                            KDFullName[strlen(KDFullName) - 1] = '\0'; KDJobTitle[strlen(KDJobTitle) - 1] = '\0'; KDHeadRegion[strlen(KDHeadRegion) - 1] = '\0';

                            SuccessfullyLoggedIn = true; KDLoggedIn = KD;

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
            puts("ERROR: Input yang diterima tidaklah valid!");
            puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");
        } else if (RSOption == 2) {
            puts("ERROR: Nama pengguna dan/atau kata sandi salah!");
            puts("... Silahkan untuk diperiksa kembali (tidak ada batasan pengecekan)!");
        }
        
        puts("");
        AcceptInputOption("> Sebelum itu, ingin melanjutkan? [1: Ya, 0: Tidak]: ", Continuing)
        if ((bool)Continuing) { CheckInvalidInput = false; ClientLobbyMenu(); }
        else { CheckInvalidInput = false; HomeMenu(); }
    }

    if (RSOption == 0) {
        puts("Selamat Datang di aplikasi: D'Wakanda!");
        puts("Anda berada dalam lobi: Client :: Sektor Industri.");

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

            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda berada dalam lobi: Client :: Sektor Industri.");

            puts("");
            puts("Silakan untuk memasukkan EMPAT (4) kredensial baru Anda seperti berikut:");
            if (CountRegists >= 2) printf("... 1. Nama Lengkap:  %s\n", SISignIn.FullName);
            if (CountRegists >= 3) printf("... 2. Nama Industri: %s\n", SISignIn.IndustryName);
            if (CountRegists >= 4) printf("... 3. Nama Pengguna: %s\n", SISignIn.Username);
            if (CountRegists >= 5) { printf("... 4. Kata Sandi:  "); for (size_t i = 0; i < strlen(SISignIn.Password); i++) { printf("*"); } printf("\n"); }
            if (CountRegists < 2)  printf("... 1. Nama Lengkap:  (maks. 128 karakter)\n");
            if (CountRegists < 3)  printf("... 2. Nama Industri: (maks. 128 karakter)\n");
            if (CountRegists < 4)  printf("... 3. Nama Pengguna: (maks. 128 karakter)\n");
            if (CountRegists < 5)  printf("... 4. Kata Sandi:    (8-16 karakter)\n");
            
            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Lengkap: ", SISignIn.FullName);
                if (strlen(SISignIn.FullName) < 2 || strlen(SISignIn.FullName) > 128) {
                    puts("");
                    puts("ERROR: Data nama lengkap melebihi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.FullName[strlen(SISignIn.FullName) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Nama Industri: ", SISignIn.IndustryName);
                if (strlen(SISignIn.IndustryName) < 2 || strlen(SISignIn.IndustryName) > 128) {
                    puts("");
                    puts("ERROR: Data nama industri melebihi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.IndustryName[strlen(SISignIn.IndustryName) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 3) {
                AcceptInputText("Nama Pengguna: ", SISignIn.Username);
                if (strlen(SISignIn.Username) < 2 || strlen(SISignIn.Username) > 128) {
                    puts("");
                    puts("ERROR: Data nama pengguna melebihi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.Username[strlen(SISignIn.Username) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 4) {
                AcceptInputText("Kata Sandi: ", SISignIn.Password);
                if (strlen(SISignIn.Password) < 9 || strlen(SISignIn.Password) > 17) {
                    puts("");
                    puts("ERROR: Data kata sandi belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; SISignIn.Password[strlen(SISignIn.Password) - 1] = '\0'; ClientLobbyMenu(); }
            }

            if (CountRegists == 5) {
                ClearScreen();

                puts("SUCCESS: Sektor industri baru telah berhasil didaftarkan!");
                puts("INFO: Silakan untuk melanjutkan interaksi berikut dengan masuk ke menu sign-in/login... .");
                
                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");

                WritePublicSektorIndustri(false);

                CountRegists = 1; RSOption = 2;
                SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                ClientLobbyMenu();
            }

        } else if (RSOption == 2) {
            if (access(Client_SektorIndustri, F_OK) != 0) {
                ClearScreen();

                puts("ERROR: Belum terdapat sektor industri yang terdaftarkan!");
                puts("... Silahkan untuk masuk ke menu registrasi sektor industri terlebih dahulu!");

                puts("");
                puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                system("pause");
                
                CountRegists = 1; RSOption = 1;
                SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                ClientLobbyMenu();
            }

            ClearScreen();
            puts("Selamat Datang di aplikasi: D'Wakanda!");
            puts("Anda berada dalam lobi: Client :: Sektor Industri.");

            puts("");
            puts("Silakan untuk memasukkan DUA (2) kredensial Anda seperti berikut:");
            if (CountRegists >= 2) printf("... 1. Nama Pengguna: %s\n", SISignIn.Username);
            if (CountRegists >= 3) { printf("... 2. Kata Sandi:    "); for (size_t i = 0; i < strlen(SISignIn.Password); i++) { printf("*"); } printf("\n"); }
            if (CountRegists < 2)  printf("... 1. Nama Pengguna: (wajib 16 digit)\n");
            if (CountRegists < 3)  printf("... 2. Kata Sandi:    (8-16 karakter)\n");

            puts("");
            if (CountRegists == 1) {
                AcceptInputText("Nama Pengguna: ", SI_SignInUsername);
                if (strlen(SI_SignInUsername) < 2 || strlen(SI_SignInUsername) > 128) {
                    puts("");
                    puts("ERROR: Data nama pengguna melebihi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; strncpy(SISignIn.Username, SI_SignInUsername, BUFSIZE07); SISignIn.Username[strlen(SISignIn.Username) - 1] = '\0'; ClientLobbyMenu(); }
            
            } if (CountRegists == 2) {
                AcceptInputText("Kata Sandi: ", SI_SignInPassword);
                if (strlen(SI_SignInPassword) < 9 || strlen(SI_SignInPassword) > 17) {
                    puts("");
                    puts("ERROR: Data kata sandi belum memenuhi batas yang ditentukan!");
                    puts("");
                    puts("(tekan tombol [ENTER] untuk melanjutkan...)");
                    system("pause");
                    ClientLobbyMenu();
                } else { CountRegists++; strncpy(SISignIn.Password, SI_SignInPassword, 32); SISignIn.Password[strlen(SISignIn.Password) - 1] = '\0'; ClientLobbyMenu(); }
            }

            if (CountRegists == 3) {
                RegisteredSIs = atoi(ReadLine(Client_SektorIndustri, AVAILABLE_DATA));

                for (int SI = 0; SI < RegisteredSIs; SI++) {
                    if (strcmp(SI_SignInUsername, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SI) + SI_USERNAME))) == 0 && \
                        strcmp(SI_SignInPassword, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SI) + SI_PASSWORD))) == 0) {

                            strncpy(SIFullName, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SI) + SI_FULLNAME)), BUFSIZE07);
                            strncpy(SIIndustryName, ReadLine(Client_SektorIndustri, (((OFFSET_SI + 1) * SI) + SI_INDUSTRY_NAME)), BUFSIZE07);
                            SIFullName[strlen(SIFullName) - 1] = '\0'; SIIndustryName[strlen(SIIndustryName) - 1] = '\0';

                            SuccessfullyLoggedIn = true; SILoggedIn = SI;
                            
                            CountRegists = 1; RSOption = 3; // Just to be sure to avoid the infinite loop after first-time registration.
                            SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
                    }
                }

                if (!SuccessfullyLoggedIn) {
                    CheckInvalidInput = true;
                    CountRegists = 1; RSOption = 2;
                    SISignIn.FullName[0] = 0; SISignIn.IndustryName[0] = 0; SISignIn.Username[0] = 0; SISignIn.Password[0] = 0;
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

void HomeMenu(void) {
    ClearScreen();

    int AUCOption = 0; RSOption = 0;
    if (CheckInvalidInput) {
        puts("ERROR: Input yang diterima tidaklah valid!");
        puts("... Silahkan untuk dikondisikan kembali pilihan yang telah tersedia!");
        CheckInvalidInput = false;
        
        puts("");
        puts("(tekan tombol [ENTER] untuk melanjutkan...)");
        system("pause"); HomeMenu();
    }

    puts("Selamat Datang di aplikasi: D'Wakanda!");
    puts("Anda berada dalam menu: Home Menu");
    
    puts("");
    puts("::       Anda dipersilahkan untuk memilih SATU dari TIGA opsi berikut ini!       ::");
    puts("::   Pertama, pastikan dan pahamilah dahulu peran dari siapa Anda ingin masuk!   ::");
    puts(":: Deskripsi dan peran tugas beliau dapat Anda baca pada menu: Tentang D'Wakanda ::");

    puts("");
    puts("[1] Admin  :: Kementerian Keuangan");
    puts("[2] User   :: Kepala Daerah");
    puts("[3] Client :: Sektor Industri");

    puts("");
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
            default: { CheckInvalidInput = true; HomeMenu(); } break;
        }
    }
}

int main(void) {
    /* NOTE: Always do this at the starting point... */
    fflush(stdout); fflush(stdin);
    setlocale(LC_NUMERIC, "");              //// NOTE: Formatting thousands with comma!

    WritePrivateKemenkeu();                 //// NOTE: Do this only ONCE if the file are not EXIST yet!
    WritePrivateKeranjang(true, false);     //// NOTE: Do this only ONCE if the file are not EXIST yet!
    WritePrivateKeranjang(false, false);    //// NOTE: Do this only ONCE if the file are not EXIST yet!
    HomeMenu();

    return 0;
}
