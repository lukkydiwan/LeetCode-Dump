class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int  stH=stoi(startTime.substr(0,2));
        int stM=stoi(startTime.substr(3,2));
        int stS=stoi(startTime.substr(6,2));
        int enH=stoi(endTime.substr(0,2));
        int enM=stoi(endTime.substr(3,2));
        int enS=stoi(endTime.substr(6,2));
        return (enH-stH)*3600+(enM-stM)*60+(enS-stS);
        
        
    }
};