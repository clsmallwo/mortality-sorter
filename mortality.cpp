#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>


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
    double sixtyFiveToSeventy;
    double seventytoSeventyFive;
    double seventyFivetoEighty;
    double eightyToEightyFive;
    double eightyFiveToNinety; 
    double ninetyToNinetyFive;
    double ninetyFiveToTwoThousand;
    double twoThousandToTwoThousandFive;
    double fiveToTen;
    double tenToFifteen;  
};

void simpleSortVector(vector<rowData> &data)
{
 
	
	for (int i=0; i < data.size(); i++)
		for (int j=i; j < data.size(); j++)
		if ((data[i].twoThousandToTwoThousandFive) < data[j].twoThousandToTwoThousandFive)
		{
            swap(data[i],data[j]);
		}
} 


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

static bool isThisARegion(string& s){
	string t = s;
	int left = 0;
	while (left < t.size() && t[left] == ' ') left++;
	if (left == t.size()) return false;
	int right = t.size() - 1;
	while (right > left && t[right] == ' ') right--;
	t = t.substr(left, right - left + 1);

	string l;
	for (int i = 0; i < t.size(); i++) {
		char c = t[i];
		l.push_back((char)tolower(c));
	}

	if (l.find('/') != string::npos) return true;
	if (l.find("region") != string::npos) return true;
	if (l.find("countries") != string::npos) return true;
	if (l.find("income") != string::npos) return true;

	const char* regionNames[] = {
		"world",
		"africa",
		"asia",
		"europe",
		"oceania",
		"northern america",
		"latin america and the caribbean",
		"latin america",
		"caribbean",
		"central america",
		"south america",
		"sub-saharan africa",
		"eastern africa",
		"middle africa",
		"northern africa",
		"southern africa",
		"western africa",
		"eastern asia",
		"south-eastern asia",
		"southern asia",
		"central asia",
		"western asia",
		"eastern europe",
		"northern europe",
		"southern europe",
		"western europe",
		"australia/new zealand",
		"melanesia",
		"micronesia",
		"polynesia"
	};
	int n = sizeof(regionNames) / sizeof(regionNames[0]);
	for (int i = 0; i < n; i++) {
		if (l == regionNames[i]) return true;
	}
	return false;
}

int main() {
    ifstream CSV ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
    string line = "";
    int lnNum = 1;
    vector<rowData> data;
    if (CSV.is_open()){
        while (getline(CSV, line)) {
            lnNum++;
            if (lnNum <= 18) {
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
                        case 8: currRow.sixtyFiveToSeventy = parseDoubleSafe(sect); break;
                        case 9: currRow.seventytoSeventyFive = parseDoubleSafe(sect); break;
                        case 10: currRow.seventyFivetoEighty = parseDoubleSafe(sect); break;
                        case 11: currRow.eightyFiveToNinety = parseDoubleSafe(sect); break;
                        case 12: currRow.ninetyToNinetyFive = parseDoubleSafe(sect); break;
                        case 13: currRow.ninetyFiveToTwoThousand = parseDoubleSafe(sect); break;
                        case 14: currRow.twoThousandToTwoThousandFive = parseDoubleSafe(sect); break;
                        case 15: currRow.fiveToTen = parseDoubleSafe(sect); break;
                        case 16: currRow.tenToFifteen = parseDoubleSafe(sect); break;
                        default: break;
                    }
                    buildInc++;
                    sect.clear();
                } else {
                    sect.push_back(c);
                }
            }
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
                    case 8: currRow.sixtyFiveToSeventy = parseDoubleSafe(sect); break;
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
    
    simpleSortVector(data);
    int rank = 0;
    
    vector<rowData> developedData;

    ofstream outFile("sorted.csv");
    ofstream outFileD("sorteddeveloped.csv");

    vector<string> developedCountries{"Japan", "Italy", "Switzerland", "Iceland", "Spain", "Australia", 
            "Sweden", "France", "Canada", "New Zealand", "Luxembourg", "Norway", "Netherlands", "Micronesia (Fed. States of)", 
            "Austria", "Germany", "Greece", "Ireland", "Portugal", "Belgium", "Finland", "United Kingdom", "Malta", 
            "Slovenia", "Denmark", "Cyprus", "United States of America", "Czech Republic", "Albania", "Poland", "Croatia", 
            "Bosnia and Herzegovina", "Slovakia", "Montenegro", "Hungary", "Romania", "Armenia", "Bulgaria", "Latvia", 
            "Lithuania", "Republic of Moldova", "Belarus", "Ukraine", "Russian Federation"};


     for (const rowData &r : data) {
        rank++;

        string temp = r.area;


        if(!isThisARegion(temp)) {
        outFile 
            << r.idx << ','
            << '"' << r.variant << '"' << ','
            << '"' << r.area << '"' << ','
            << '"' << r.notes << '"' << ','
            << r.countryCode << ','
            << r.fiftyToFiftyfive << ','
            << r.fiftyFiveToSitxy << ','
            << r.sixtyToSixtyFive << ','
            << r.sixtyFiveToSeventy << ','
            << r.seventyFivetoEighty << ','
            << r.eightyFiveToNinety << ','
            << r.ninetyToNinetyFive << ','
            << r.ninetyFiveToTwoThousand << ','
            << r.twoThousandToTwoThousandFive << ','
            << r.fiveToTen << ','
            << r.tenToFifteen
          //  << "\n RANK:" << rank
            << '\n';
        }

            for (int i = 0; i < developedCountries.size(); i++) { 
                if (developedCountries[i] == r.area) {
                developedData.push_back(r);
                }
            }


        
     }
    outFile.close();


    rank = 0;
    cout << "\n======================================\n\n";

    for (const rowData j: developedData){
        outFileD 
            << j.idx << ','
            << '"' << j.variant << '"' << ','
            << '"' << j.area << '"' << ','
            << '"' << j.notes << '"' << ','
            << j.countryCode << ','
            << j.fiftyToFiftyfive << ','
            << j.fiftyFiveToSitxy << ','
            << j.sixtyToSixtyFive << ','
            << j.sixtyFiveToSeventy << ','
            << j.seventyFivetoEighty << ','
            << j.eightyFiveToNinety << ','
            << j.ninetyToNinetyFive << ','
            << j.ninetyFiveToTwoThousand << ','
            << j.twoThousandToTwoThousandFive << ','
            << j.fiveToTen << ','
            << j.tenToFifteen
        //    << "\n RANK:" << rank
            << '\n';
    }
    outFileD.close();


    return 0; 
}