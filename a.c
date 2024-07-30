#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BUFSIZE07 128
#define BUFSIZE10 1024
#define BUFSIZE16 65536
#define UserCartStore_Keranjang "a.txt"

char *ReadAndPrintLine(const char* SourceTextFile, intmax_t Line) {
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
    fclose(FSource); ReturnFDBuffer = "None"; return ReturnFDBuffer;
}

void OverWriteStringAtLine(const char* FSourceTxtFile, const char* NewOverWriteString, const int EncryptionKey, signed int AtSpesificLine) {
	FILE *FSource, *FDestination, *FCopyAndDecrypting, *FTempDestination;
	int AtLine = AtSpesificLine, LineControl = 0, BufLen = 0;
	char FDBuffer[BUFSIZE16], NewlyString[BUFSIZE16], FileName[BUFSIZE16];      
	char OverWriteStringLine[BUFSIZE16], FTempDestinationTxtFile[BUFSIZE16] = "TempDestination.txt", DeleteTempDestinationTxtFile[BUFSIZE16];
	
	FCopyAndDecrypting = fopen(FSourceTxtFile, "r");
	FTempDestination   = fopen("FTempDestination.txt", "w");
	while (fgets(FDBuffer, sizeof(FDBuffer), FCopyAndDecrypting) != 0) {
		BufLen = strlen(FDBuffer);
		for (int i = 0; i < BufLen; i++) FDBuffer[i] += EncryptionKey;
		fputs(FDBuffer, FTempDestination);
	} fclose(FCopyAndDecrypting); fclose(FTempDestination);

	strncpy(FileName, FSourceTxtFile, BUFSIZE16);
	FSource      = fopen("FTempDestination.txt", "r");
	FDestination = fopen(FTempDestinationTxtFile, "w");
	if (!FSource)      { }
	if (!FDestination) { }

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

int CountBufferEOF(const char* SourceString) {
    FILE *FSource = fopen(SourceString, "r");
    int Lines = 0;
    
    while((fscanf(FSource, "%*[^\n]"), fscanf(FSource, "%*c")) != EOF) { Lines++; }
    Lines++; fclose(FSource); return Lines;
}

typedef struct User {
    char FullName[BUFSIZE07], NIK[32], Email[BUFSIZE07], Password[32];
    char BirthPlaceDate[BUFSIZE07], JobTitle[BUFSIZE07], HeadRegion[BUFSIZE07];
} KepalaDaerah;

typedef struct CartStore {
    int Status;
    char Requester[BUFSIZE07], Accepter[BUFSIZE07], ProductInDemand[BUFSIZE07];
} Keranjang;

int main(void) {
    FILE *AccessCart;
    KepalaDaerah KDList = { 0 };
    Keranjang CList = { 0 };

    const char *SIFullName = "Rafhan", *SIIndustryName = "PT. Bebas Jaya";
    char FinalReqs[BUFSIZE07];
    char *DisplayProductName = "Laptop/PC", *DisplayProductStock = "100", *DisplayProductPrice = "2500000000";
    char CurrentKDFile[BUFSIZE10];
    bool CheckForCurrentKD = false;
    int AvailableReqs = 0, MaxReq = atoi(ReadAndPrintLine("a.txt", 1));

    strcpy(KDList.FullName, "Nue");
    strcpy(KDList.JobTitle, "Gubernur");
    strcpy(KDList.HeadRegion, "Bali");

    strcpy(CurrentKDFile, "New_"UserCartStore_Keranjang);
    AccessCart = fopen(CurrentKDFile, "w");

    fprintf(AccessCart, "0\n");
    for (int i = 0; i < MaxReq; i++) {
        strcpy(CList.Requester, ReadAndPrintLine("a.txt", ((4 + 1) * i) + 3));
        strcpy(CList.Accepter, ReadAndPrintLine("a.txt", ((4 + 1) * i) + 4));
        strcpy(CList.ProductInDemand, ReadAndPrintLine("a.txt", ((4 + 1) * i) + 5));
        CList.Status = atoi(ReadAndPrintLine("a.txt", ((4 + 1) * i) + 6));
        CList.Requester[strlen(CList.Requester) - 1] = '\0'; CList.Accepter[strlen(CList.Accepter) - 1] = '\0'; CList.ProductInDemand[strlen(CList.ProductInDemand) - 1] = '\0';
        
        if (atoi(ReadAndPrintLine("a.txt", ((4 + 1) * i) + 6)) == 2 && strstr(CList.Requester, KDList.FullName) != NULL && strstr(CList.Requester, KDList.JobTitle) != NULL && strstr(CList.Requester, KDList.HeadRegion) != NULL) {
            continue;
        } else {
            AvailableReqs++;
            fprintf(AccessCart, "\n%s\n%s\n%s\n%d\n", CList.Requester, CList.Accepter, CList.ProductInDemand, CList.Status);
        }
    } fclose(AccessCart);

    snprintf(FinalReqs, sizeof(FinalReqs), "%d", AvailableReqs);
    OverWriteStringAtLine("New_"UserCartStore_Keranjang, FinalReqs, 0, 1);

    // for (int Line = 1; Line <= CountBufferEOF("a.txt"); Line++) {
    //     if (Line == 1) {
    //         fprintf(AccessCart, "%d\n", atoi(ReadAndPrintLine("a.txt", Line)) - 1);
    //     } else if (Line == ((4 + 1) * AvailableReqs) + 2) {
    //         fprintf(AccessCart, "\n");
    //     }
        
    //     if (Line != 1 && Line != ((4 + 1) * AvailableReqs) + 2) {
    //         if (strstr(ReadAndPrintLine("a.txt", Line), KDList.FullName) != NULL && strstr(ReadAndPrintLine("a.txt", Line), KDList.JobTitle) != NULL && strstr(ReadAndPrintLine("a.txt", Line), KDList.HeadRegion) != NULL) {
    //             CheckForCurrentKD = true;
    //             continue;
    //         } else if (CheckForCurrentKD && strstr(ReadAndPrintLine("a.txt", Line), SIFullName) != NULL && strstr(ReadAndPrintLine("a.txt", Line), SIIndustryName) != NULL) {
    //             continue;
    //         } else if (CheckForCurrentKD && strstr(ReadAndPrintLine("a.txt", Line), DisplayProductName) != NULL && strstr(ReadAndPrintLine("a.txt", Line), DisplayProductStock) != NULL && strstr(ReadAndPrintLine("a.txt", Line), DisplayProductPrice) != NULL) {
    //             continue;
    //         } else if (CheckForCurrentKD && Line == ((4 + 1) * AvailableReqs) + 6) {
    //             CheckForCurrentKD = false;
    //             fprintf(AccessCart, "0\n");
    //         } else if (!CheckForCurrentKD) {
    //             fprintf(AccessCart, "%s", ReadAndPrintLine("a.txt", Line));
    //         }
    //     }
    // } fclose(AccessCart);
}