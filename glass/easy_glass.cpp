#include <iostream>
#include <list>
#include<array>
#include<map>
#include<vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}




struct Map_id{
map<int, pair<double, int>> id_map;
};

struct SortedList {
    list<array<double, 2>> data;
    int max_1;

    void printlist(string flag = ""){
        int i = 0;
        if(flag ==  "ASK"){
            cout << "ASK" << ", " ;
        for (const auto& item : data) {
            
        cout << setprecision(9) <<" " << item[0] << ",  " << item[1] << ", ";
        i++;
    }
    cout <<  endl;
    
    }
        else{
            cout << "BID" << ", " ;
            //list<int>::reverse_iterator rit;
        for (auto rit = data.rbegin(); rit != data.rend(); ++rit, i++) {
        cout  <<setprecision(9)<<" "  << (*rit)[0] << ", " << (*rit)[1] << ", " ;
        } 
        cout <<  endl;
    } 

    }
    

    void insertElement(array<double, 2> element) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if ((*it)[0] > element[0]) {
                data.insert(it, element);
                return;
            }
        }
        if (data.size() > max_1)
            max_1 = data.size();
        data.push_back(element);
    }

    int findElement(double element) {
    int index = 0;
    for (const auto& item : data) {
        if (item[0] == element) {
            return index;
        }
        index++;
    }
    return -1; // Возвращаем -1, если элемент не найден
}

    void removeElement(double element) {

        int position = findElement(element);
        if (position < 0 || position >= data.size()) {
            cout << "Некорректная позиция элемента" << endl;
            return;
        }

        auto it = data.begin();
        advance(it, position);
        data.erase(it);
    }


};



void chegde_glass(SortedList& slist, Map_id& idmap, string flag, int id, double prise=0,  int size=0){
        
        
        if (flag == "delete"){
                if (idmap.id_map.find(id) == idmap.id_map.end()) 
                return ;
            

            
            prise = ((idmap.id_map)[id]).first;
            size = ((idmap.id_map)[id]).second;
            idmap.id_map.erase(id);

            int i = slist.findElement(prise);

            auto it = slist.data.begin();
            std::advance(it, i);
            (*it)[1] -= size;

            if((*it)[1] <= 0)   
                slist.removeElement(prise);
        }

        if(flag == "added"){
            pair<double, int> a = make_pair(prise,size);
            idmap.id_map[id] = a;
               // cout << "new id" << id << endl ; 
            int i = slist.findElement(prise);
            auto it = slist.data.begin();
            std::advance(it, i);
            array<double,2> v = {prise, size*1.0} ;


            if (i != -1)
                (*it)[1] += size;
            else     
                slist.insertElement(v);

        }

        if(flag == "changed"){
            int delta  = size - idmap.id_map[id].second;

            int i = slist.findElement(prise);
            auto it = slist.data.begin();
            std::advance(it, i);
            (*it)[1] += delta;

            idmap.id_map[id].second = size;
             

        }


    }



void removeNewlines(std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != '\n') {
            result += c;
        }
    }
    str = result;
}

double transtime(std::string str){
        vector<string> time, hours;
        
        time = split(str, ":");

        // double hour  = stod(split(time[0],"T")[1]);
        // double minut = stod(time[1]);
        double sec;
        if(time.size() > 2)
            sec = stod(time[2]);
        else 
             sec = 0;
        
        return sec;
        

}



string flag_parsing(string str){

                    if(str[0] == 'a')
                        return "added";
                    if(str[0] == 'c')
                        return  "changed";
                    if(str[0] == 'd')
                         return "deleted";


return "";

}

int main() {    

    Map_id  ask_map_id;
    Map_id bid_map_id;
    SortedList bid_list;
    SortedList ask_list;
    vector <string> rdata;
    std::string line;
    std::string data;
    bid_list.max_1 = 0;
    ask_list.max_1 = 0;
    
    std::ifstream inputFile("/home/jon/vega/glass/some_data/order_book.csv"); // Открытие файла для чтения
    if (inputFile.is_open()) { // Проверка успешного открытия файла
       
        while (std::getline(inputFile, line)) { // Чтение строки из файла
            data += line;
        }
        inputFile.close();

        removeNewlines(data);
    
    }
        //data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());


        
    rdata = split(data, ",");
    
    cout << "sec, count , bid or ask, ";

    for (int i  = 0; i < 329; i++){    
    cout << i << " prise, "  << i << " size, ";}

    cout << endl;
    

    long long max_1 = 0;
    double sec = 0;
    string flag = "";
    int id = 0;
    double  prise = 0;
    double size = 0;
    string bid_or_ask = "";
    int k = 6;
    int count_1 = 0;
    bool flg = 0;
    int l = 0;
    
    for (int i = 6; i < rdata.size() - 1000; i++){
                

                if (ask_map_id.id_map.size() > max_1)
                    max_1 = ask_map_id.id_map.size();

                if (bid_map_id.id_map.size() > max_1)
                    max_1 = bid_map_id.id_map.size();
              if (i % 6 == 1){
                 sec = transtime(rdata[i]);
                 }

                
             if(i % 6 == 3)
                     id = stoi(rdata[i]);      

                  
            
            if(i % 6 == 2)
                    bid_or_ask = rdata[i];  

        //     if ( 392500< i&& i < 392500 + 1000){
        // //      cout << " sec= " << sec << endl;
        //       cout << " flag = " << flag << endl;
        // //    // cout << " id = "  << id << endl;
        // //    // cout << "bid Or ask " << bid_or_ask << endl;  
        //       }


            if ( flag == "changed" || flag == "added"  ){
                
                if(i % 6 == 4)
                    prise =  stod(rdata[i]);
                if(i % 6 == 5) 
                    size = stod(rdata[i]);

                if(i % 6 == 0 && bid_or_ask == "ASK" && i > 6){
                   // cout << " I'm inn";
                    chegde_glass(ask_list,ask_map_id, flag, id, prise , size);
                   // cout << " absolutly";
                    }

                if(i % 6 == 0 && bid_or_ask == "BID" && i >6 )
                    chegde_glass(bid_list,bid_map_id, flag, id, prise , size);
                
                
        }   
                

            else{    
                    if (i % 6 == 0 && i > 6){
                    chegde_glass(ask_list,ask_map_id, flag, id, prise , size);
                    chegde_glass(bid_list,bid_map_id, flag, id, prise , size);
                    }

            }

            if (i % 6 == 0)
                 flag = flag_parsing(rdata[i + 6]);
//             
//          
                
            if ((sec - count_1) >= 1 || (count_1 == 59 && sec < 1 )){
                cout  << sec << ", "<< l <<", ";

                ask_list.printlist("ASK");

                cout << sec << ", " << l <<", "; 
                bid_list.printlist("BID");

                count_1 = (count_1 + 1) % 60;

                l++;
                }
            
         

    }

    
    
    return 0;
    }
   
            
        



