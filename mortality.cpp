#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std; 

struct rowData {
    int idx;
    string variant; 
    string area; 
    string notes;
    int countryCode;
    double fiftyToFiftyfive;
    double fiftyFiveToSitxy;
    double sixtyToSixtyFive; 
    double sixtyFivetoSeventyFive;
    double seventyFivetoEighty;
    double eightyToEightyFive;
    double eightyFiveToNinety; 
    double ninetyToNinetyFive;
    double ninetyFiveToTwoThousand;
    double twoThousandToTwoThousandFive;
    double fiveToTen;
    double tenToFifteen;  
};

int main() {
    ifstream CSV ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
    string line = "";
    string word = "";
    int lnNum = 1;
    int idxSt = 0;
    int idxEn;
    int buildInc;
    vector<rowData> data;
    rowData currRow;
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
                switch (buildInc) {
                    case 0:
                        currRow.idx = stod(sect);
                        break;
                    case 1:
                        currRow.variant = sect /*.substr(1,sect.length()-2); */;
                        break;
                    case 2:
                        currRow.area = sect /*.substr(1,sect.length()-2); */;
                        break;
                    case 3:
                        currRow.notes = sect /*.substr(1,sect.length()-2); */;
                        break;
                    case 4: 
                        cout << sect;
                        currRow.countryCode = stoi(sect);
                        break;
                    case 5:
                        currRow.fiftyToFiftyfive = stod(sect);
                        break;
                    case 6:
                        currRow.fiftyFiveToSitxy = stod(sect);
                        break;
                    case 7:
                        currRow.sixtyToSixtyFive = stod(sect);
                        break;
                    case 8:
                        currRow.sixtyFivetoSeventyFive = stod(sect);
                        break;
                    case 9:
                        currRow.seventyFivetoEighty = stod(sect);
                        break;
                    case 10:
                        currRow.eightyFiveToNinety = stod(sect);
                        break;
                    case 11:
                        currRow.ninetyToNinetyFive = stod(sect);
                        break;
                    case 12:
                        currRow.ninetyFiveToTwoThousand = stod(sect);
                        break;
                    case 13:
                        currRow.twoThousandToTwoThousandFive = stod(sect);
                        break;
                    case 14:
                        currRow.fiveToTen = stod(sect);
                        break;
                    case 15:
                        currRow.tenToFifteen = stod(sect);
                        break;
                    
                } 
                buildInc++;
                sect = "";
                
                idxSt = idxEn;
            }
            buildInc = 0;
            data.push_back(currRow);
        }
        }
        CSV.close();

    }
    else cout << "Can't open that stuff";
    
    return 0; 
}