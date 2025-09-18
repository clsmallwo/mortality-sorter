#include <iostream>
#include <fstream>
#include <sstream>


using namespace std; 

struct {
    int idx;
    string variant; 
    string area; 
    string notes;
    int countryCode;
    float fiftyToFiftyfive;
    float fiftyFiveToSitxy;
    float sixtyToSixtyFive; 
    float sixtyFivetoSeventyFive;
    float seventyFivetoEighty;
    float eightyToEightyFive;
    float eightyFiveToNinety; 
    float twoThousandToTwoThousandFive;
    float fiveToTen;
    float tentoFifteen;

    
}

int main() {
    ifstream CSV ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
    string line = "";
    string word = "";
    int lnNum = 1;
    int idxSt = 0;
    int idxEn;
    if (CSV.is_open()){
        while (getline(CSV, line)) {
            string sect;
            lnNum++; 
            if(lnNum > 17);
            {
            for (int i = 0; i < line.length(); i++){
                if(line[i] == ','){
                    idxEn = i;
                }
                for (int j = idxSt+1; j < idxEn; j++){
                    sect += line[j];
                }
                cout << sect << "|";
                sect = "";
                
                idxSt = idxEn;
            }

        }
        }
        CSV.close();

    }
    else cout << "Can't open that stuff";
    
    return 0; 
}