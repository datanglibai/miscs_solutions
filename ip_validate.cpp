#include "iostream"
#include <regex>
using namespace std;

string validIPAddress(string IP) {
    //not that correct yet...
    string reg_v4 = "^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$";
    string reg_v6 = "^((?:[0-9A-Fa-f]{1,4}))((?::[0-9A-Fa-f]{1,4}))*::((?:[0-9A-Fa-f]{1,4}))((?::[0-9A-Fa-f]{1,4}))*|((?:[0-9A-Fa-f]{1,4}))((?::[0-9A-Fa-f]{1,4})){7}$";
    
    regex regexp_v4(reg_v4,regex_constants::basic);
    regex regexp_v6(reg_v6,regex_constants::basic);
    
    if (std::regex_match(IP, regexp_v4)) {
        return "IPv4";
    } 
        
    if(std::regex_match(IP, regexp_v6)){
        return "IPv6";
    }
      
    return "Neither";
}

int main(int argc, char *argv[])
{
    return 0;
}