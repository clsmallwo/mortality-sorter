#include <iostream>
#include <fstream>
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

static int parseIntSafe(const string &text) {
    try {
        size_t consumed = 0;
        int value = stoi(text, &consumed);
        if (consumed != text.size()) return 0;
        return value;
    } catch (...) {
        return 0;
    }
}

static double parseDoubleSafe(const string &text) {
    try {
        size_t consumed = 0;
        double value = stod(text, &consumed);
        if (consumed != text.size()) return 0.0;
        return value;
    } catch (...) {
        return 0.0;
    }
}

int main() {
    ifstream CSV ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
    string line = "";
    int lnNum = 1;
    vector<rowData> data;
    if (CSV.is_open()){
        while (getline(CSV, line)) {
            lnNum++;
            if (lnNum <= 17) {
                continue; 
            }

            rowData currRow; 
            string sect = "";
            int buildInc = 0;
            bool inQuotes = false;
            for (size_t i = 0; i < line.size(); i++){
                char c = line[i];
                if (c == '"') {
                    if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                        sect.push_back('"');
                        i++; 
                    } else {
                        inQuotes = !inQuotes;
                    }
                } else if (c == ',' && !inQuotes) {
                    switch (buildInc) {
                        case 0: currRow.idx = parseIntSafe(sect); break;
                        case 1: currRow.variant = sect; break;
                        case 2: currRow.area = sect; break;
                        case 3: currRow.notes = sect; break;
                        case 4: currRow.countryCode = parseIntSafe(sect); break;
                        case 5: currRow.fiftyToFiftyfive = parseDoubleSafe(sect); break;
                        case 6: currRow.fiftyFiveToSitxy = parseDoubleSafe(sect); break;
                        case 7: currRow.sixtyToSixtyFive = parseDoubleSafe(sect); break;
                        case 8: currRow.sixtyFivetoSeventyFive = parseDoubleSafe(sect); break;
                        case 9: currRow.seventyFivetoEighty = parseDoubleSafe(sect); break;
                        case 10: currRow.eightyFiveToNinety = parseDoubleSafe(sect); break;
                        case 11: currRow.ninetyToNinetyFive = parseDoubleSafe(sect); break;
                        case 12: currRow.ninetyFiveToTwoThousand = parseDoubleSafe(sect); break;
                        case 13: currRow.twoThousandToTwoThousandFive = parseDoubleSafe(sect); break;
                        case 14: currRow.fiveToTen = parseDoubleSafe(sect); break;
                        case 15: currRow.tenToFifteen = parseDoubleSafe(sect); break;
                        default: break;
                    }
                    buildInc++;
                    sect.clear();
                } else {
                    sect.push_back(c);
                }
            }
            // process last field (if any)
            if (!inQuotes) {
                switch (buildInc) {
                    case 0: currRow.idx = parseIntSafe(sect); break;
                    case 1: currRow.variant = sect; break;
                    case 2: currRow.area = sect; break;
                    case 3: currRow.notes = sect; break;
                    case 4: currRow.countryCode = parseIntSafe(sect); break;
                    case 5: currRow.fiftyToFiftyfive = parseDoubleSafe(sect); break;
                    case 6: currRow.fiftyFiveToSitxy = parseDoubleSafe(sect); break;
                    case 7: currRow.sixtyToSixtyFive = parseDoubleSafe(sect); break;
                    case 8: currRow.sixtyFivetoSeventyFive = parseDoubleSafe(sect); break;
                    case 9: currRow.seventyFivetoEighty = parseDoubleSafe(sect); break;
                    case 10: currRow.eightyFiveToNinety = parseDoubleSafe(sect); break;
                    case 11: currRow.ninetyToNinetyFive = parseDoubleSafe(sect); break;
                    case 12: currRow.ninetyFiveToTwoThousand = parseDoubleSafe(sect); break;
                    case 13: currRow.twoThousandToTwoThousandFive = parseDoubleSafe(sect); break;
                    case 14: currRow.fiveToTen = parseDoubleSafe(sect); break;
                    case 15: currRow.tenToFifteen = parseDoubleSafe(sect); break;
                    default: break;
                }
            }

            data.push_back(currRow);
        }
        CSV.close();
    }
    else {
        cout << "Can't open that stuff";
    }
    
    // Print out the vector contents
    cout << "Loaded rows: " << data.size() << "\n";
    for (const auto &r : data) {
        cout 
            << r.idx << ','
            << '"' << r.variant << '"' << ','
            << '"' << r.area << '"' << ','
            << '"' << r.notes << '"' << ','
            << r.countryCode << ','
            << r.fiftyToFiftyfive << ','
            << r.fiftyFiveToSitxy << ','
            << r.sixtyToSixtyFive << ','
            << r.sixtyFivetoSeventyFive << ','
            << r.seventyFivetoEighty << ','
            << r.eightyFiveToNinety << ','
            << r.ninetyToNinetyFive << ','
            << r.ninetyFiveToTwoThousand << ','
            << r.twoThousandToTwoThousandFive << ','
            << r.fiveToTen << ','
            << r.tenToFifteen
            << '\n';
    }
    
    return 0; 
}