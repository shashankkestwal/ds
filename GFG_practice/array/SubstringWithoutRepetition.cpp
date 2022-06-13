#include <bits/stdc++.h>
using namespace std;

int longestNONRepeatedSubstring(string s) {
    unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        int ans = 0;
        int temp = 0;
        for(int i = s.length() -1 ; i >= 0; i-- ) {
            if(temp > umap[s[i]]) {
                ans -= umap[s[i]];
            } else {
                ans += umap[s[i]];
            }
            temp = umap[s[i]];             
        }
        return ans;
}



bool strongPasswordCheckerII(string password) {
        bool hasLowerCase =  false;
        bool hasUpperCase = false;
        bool hasDigit = false;
        bool hasSpecialChars = false;
        string specialChars = "!@#$%^&*()-+";
        if(password.length() >= 8) {
            for(int i = 0; i < password.length(); i++) {
                if(password[i] >='a' && password[i] <='z') {

                    hasLowerCase = true;
                }
                if(password[i] >='A' && password[i] <='Z') {
                    hasUpperCase = true;
                }
                if(password[i] >= '0' && password[i] <= '9') {
                    hasDigit = true;
                }
                for(int j = 0; j < specialChars.length(); j++) {
                    if (password[i] == specialChars[j]) {
                        hasSpecialChars = true;
                        break;
                    }
                }
                
                if(i >= 1 && password[i] == password[i-1])  {
                    return false;
                }
                 
            }
        }
        // cout << hasLowerCase << hasUpperCase << hasSpecialChars << hasDigit;
        if(hasLowerCase && hasUpperCase && hasSpecialChars && hasDigit) {
            return true;
        }
        return false;
    }

void sayDigits(int n) {
    if(n == 0) {
        return;
    }
    int temp = n%10;
    sayDigits(n/10);
    cout << temp << "  ";
}

bool isSorted(int * arr , int size) {
    if(size - 1 < 0) {
        return true;
    }
    cout << arr[size-1] << "   " << arr[size]<< endl;
    if(arr[size-1] > arr[size]) {
        return false;
    } else {
        return isSorted(arr, size-1);
    }
}

int sumRecursive(int * arr , int size) {
    if (size <= 0)
        return 0;
    return sumRecursive(arr, size-1) + arr[size-1];
}


void print(int arr[], int size) {
    cout << "Call to print";
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] <<"  ";
    } cout << endl;
}

bool linearSearch(int * arr, int size , int key) {
    
    if(size <= 0) return false;
    // print(arr, size);
    if(arr[size-1] == key) return true;
    else return linearSearch(arr, size-1, key);
}

bool sortArr(int a, int b) {
    return a < b;
}
int binarySearch(vector<int> arr, int start , int end, int key ) {
    if(start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(arr[mid] == key) {
        return mid;
    }
    if(arr[mid] > key) {
        return binarySearch(arr, start, mid -1 , key);
    } else {
        return binarySearch(arr, mid + 1, end , key);
    }
}


int main() {
    vector<int> arr = {-1,0,3,5,9,12};
    int key = 13;

    sort(arr.begin(), arr.end());

    cout << binarySearch(arr, 0, 6, 13);


    // cout << linearSearch(arr, 5, 0);

    // vector <string> ideas = {"vko","weclx","zvmr","uviw","saqckqsae","qmtnhuvei","dbecvxnf","rzqdbslryy","lcubdlpe","lklqhv","zueqijqx","es","vemlotqscp","gaq","qqvnmcfb","rrzgvhgtq","r","twcwwefon","mcqauyh","tbjxnluz","pemlotqscp","gipefxu","lbel","cpw","tsksova","qcej","aockrieh","mnknps","slebb","dxjkcfrl","oukuuqh","zchu","dxlyaegw","ntxo","t","vgqjyqsqs","xtjuijzu","sbwi","ctxo","uleqkixvv","jlpdiyd","owrwfpxmm","ubh","fbel","ehivyjl","rqnnag","zp","totd","ris","ylewubim","adjcrxniek","msiz","hohqzp","isbh","nursdl","li","h","gzv","oez","sueqijqx","zgl","vfdns","opthfminwn","n","vtdcpuhbfx","bmydhsahp","pptks","i","y","dmlyrme","uay","stpcos","fynvq","dpinbd","zvxmpz","v","dpzch","wkds","jxp","crzgvhgtq","u","xczgkv","bityp","mgcqz","dxp","thr","o","c","adfeteaudm","zhxvzqwa","jgbltsg","ettg","ypgxg","uuenijm","flbccyoy","rcvktgjf","jryiwqrxfu","f","jz","a","hcauiihqbl","jsnmlfqyb","rtdw","rfhf","dz","j","qi","mnksiyrm","nkv","ecubdlpe","mfegqzfupn","ddwknaptw","cpbprbunx","zopdaetiua","ltxlk","ajed","bxxfy","lmmq","dzv","tinwjkhbn","fmpwqluzwp","erdvquynmr","updjjldbx","ztdw","wrbc","gfzjelf","qpeh","meol","mnbnegzkny","ewvqbhpk","ht","gtdbpymjw","zxi","ze","srbc","tjjhtr","vvmrsnxc","ft","e","kuanmcvbmp","bgazywyupu","orhtlhxu","rgmpbs","gvvllz","ujecn","fevxyiioxj","zdttv","wrifva","guu","hpdjjldbx","qrclzbzy","tgwp","qfductm","uu","oklswwfvmg","zxtvzsp","cunis","zfhqiwn","ejbwik","idx","neftrgzy","wy","ufhf","mz","cdkrun","tzswlbkoco","zuenijm","qtexz","oevxyiioxj","iapgx","kjbwik","ecjf","mvfzr","gi","hs","pbaa","cat","wikkk","b","tfatzvdqy","oakcufbqx","l","oz","fysihhmj","ubdngfcdu","ubkhly","uuzxsidnsb","cegm","xtw","lityp","yauup","zaqadeyyp","jdosncc","wh","dpnzhhfr","czfpvfzcq","s","spw","srgqffdbem","jhwll","dgpalou","bfgsy","fjqibgxx","zic","pmhenjgd","hvnrzqijgc","gwavvvej","nvn","trsxkruw","rywuxmh","bxarphzve","ipn","vursdl","aucnzyk","qv","oig","uabdtkl","cqbmdj","opaf","dlng","ds","tdbhb","hphjnpons","zk","akds","xt","jkwwxb","ifkulp","qko","lnyyv","xbc","kphukriu","bswhj","abcrds","tvmb","ldyr","fqcgus","vgwp","jvvllz","lmydhsahp","tptx","ligzk","kig","fopdaetiua","yfgwlflr","uep","dysihhmj","ktjuijzu","pvmr","oyodlblld","xvf","mbzhpkxoed","pgd","p","kvf","yowijqf","hztakvx","jqcia","oursdl","frialqo","pv","pjstfiiz","fsksova","zywxuhgl","gmbxojzxtv","rfu","q","hfzjelf","ywcwwefon","djzz","qwmbilqf","fbsggnj","znnta","zkc","tnllaloory","ibuz","kus","ge","cqcia","wfoxwcb","ynwqvbnhyc","ls","mmtnhuvei","ajvmxedde","vukvyffk","knvnw","wukvyffk","wikvaxuh","pu","htno","vnowffrdcd","m","hqkitao","uqczdmc","chxvzqwa","jktq","avg","pbgqn","qxhv","zkmkqn","nrknpciquu","mvbzqj","ybcfoxuuma","jwq","egwr","tfjndoowqt","wx","xk","kcbiiha","tnsrbfgnrk","xaawv","kgqjyqsqs","bz","ap","drlqmcy","rmkxwvbgib","wdosncc","uo","htvmbaakq","bwdsy","ns","lsti","nq","yuuvy","pnbrqryv","gok","x","qnjq","fhkqyuxeq","qchifdoow","w","aviw","red","cvxuh","xac","fd","bslg","nv","tzfpvfzcq","ihxqfrpxa","slzjvibld","xj","cxh","qwooaryqpd","vsvobxktv","ygnduvfm","bggpclnk","zlcp","bagjbno","odiitmbyd","cxjkcfrl","qdgteaok","yrkcy","hqckr","ll","qioqldzmb","oxm","pbx","rvnrzqijgc","hwa","mvooal","arifva","twjxbdupm","hcbiiha","ouanmcvbmp","qvgx","pcti","ebsggnj","zccgksiueq","wpoqxbzj","jhocoagamn","bpkvvseylx","rfzjelf","kxaux","kd","izycgczw","txclgbthb","lovyyvho","hep","ofkulp","yllnyjgn","shrn","wmpynlasy","gvxmpz","sfegqzfupn","dg","zpxeba","olflaf","co","ydsbpfydwa","wep","wcubdlpe","zgpalou","uemlotqscp","nykx","dsmxvbtaxf","gbcxxpkvts","uejn","semlotqscp","eemlotqscp","rasibkqzp","cslwjr","zhdprbilxh","xjzwknquc","tzlhjpuwt","se","of","wrxv","xqckr","ib","nmpwqluzwp","hndaiq","bjjxz","iyvgvqs","hbblhvtrd","ymgz","wnozjo","gxuinb","nofzakry","jztwgdf","ymnpdocdxy","jtmcytbgb","hv","znyyv","sjuunbl","uzycgczw","ummepwe","yryzximrh","urwgvm","yaawv","ydmfeekuw","dviyc","xal","gwrwfpxmm","pdl","zvgx","hmygbqzigp","gkd","wzfqxotc","yamegkfig","nkjcjtjr","tddpwbt","hdzpgo","lfgsy","nvmb","tqckr","jkv","phpiwbcg","jqnomtu","ksiz","jcauiihqbl","yzyutjcoh","egtiyglu","wuxatlq","xamegkfig","qzqdbslryy","anbn","diisvhfpj","qaiujw","rvdx","sc","qgudi","udpi","ijjhtr","ilzjvibld","vj","anllaloory","et","zjnh","jec","bpdjjldbx","kchaozj","npnlzxv","qlebb","wd","sbcclnab","sj","wt","kvgx","utgkypjby","bygods","uy","sdvecyzy","kptx","gdsts","wqksxzbyd","egbbhwhgi","apqanzxk","noucxk","eocxue","fdgozm","spzqksumhs","pqwlldwgo","dpeiunz","jkymlvhs","xgcqz","aedtpsk","mgazywyupu","brliv","unqne","sedtpsk","qew","ddqlbzvfv","bzqdbslryy","re","mwb","ay","usy","hegm","oykablpe","qic","nhivyjl","dtdcpuhbfx","aljbx","cgbbhwhgi","atouinpvoo","wbecvxnf","adl","dlqmel","uvlqwn","skwmdgm","gus","mcwsezhqnf","ynnta","aotpqeh","cevmw","qlommmg","cmcgfiz","mabdtkl","ucl","hdgteaok","snitnrmkh","aryiwqrxfu","zlsxxddr","ptsw","sq","lxocryokg","kcyd","ojbdttfdh","edyr","ocksmkjp","rhqfphpkm","ieqnbvzzvx","mg","aw","zooxldkj","vdenu","rdjcrxniek","beh","erkcy","kp","gpinbd","bvugfhs","agozjkhx","qcmbd","vlhdsavrc","keey","tfgwlflr","ac","jrduo","npnsbht","jsheka","nzgjzxx","eczktnmggu","vqh","halbbzawh","bndaiq","dursdl","vx","oeftrgzy","jggtwnmdq","eqczdmc","bpgrju","bwvqbhpk","oorcn","iqauy","sydomm","gjbvdqfchm","hnh","krydot","bjanw","oxv","vpeiunz","oikon","owooaryqpd","jsa","jbryy","ezgosgjact","sqh","qh","osdfil","xe","wgypd","fggcwlw","kzfpvfzcq","vo","xf","qagjbno","vospfwm","lpygdtpo","vm","sausrlm","jwsfflagv","mpzch","qapmkht","icfbcdkc","pg","luoaikoh","tsdfil","tt","xbsggnj","im","ifviqhy","pfatzvdqy","fdfimmeo","xsbh","mevxyiioxj","wok","puhgdyoiar","rwu","srzgvhgtq","qhr","pgqjyqsqs","nnugxuqgv","ryodlblld","qf","nr","wgqvwdxuyf","lkqb","llewubim","keflrudln","cpqanzxk","ipgefzxuq","qgypd","mysaju","wkmkqn","wdrpaor","rr","eqcia","ptjrthzoq","ybgq","spxeba","xyicvwlv","xoyszkymav","kr","nmmepwe","psvobxktv","pfznps","skitqsrg",
    // "pmygbqzigp","qyufnzs"};
    // int count = 0;
    //     for(int i = 0 ; i < ideas.size() ; i++) {
    //         for(int j = 0 ; j < ideas.size(); j++) {
    //             if(i == j ) {
    //                 continue;
    //             }
    //             string a = ideas[i];
    //             string b = ideas[j];
    //             char temp = a[0];
    //             a[0] = b[0];
    //             b[0] = temp;
    //             bool valid = true;
    //             for(int k = 0; k < ideas.size(); k++) {
    //                 if(a == ideas[k] || b == ideas[k]) {
    //                     valid = false;
    //                     break;
    //                 }
    //             }
    //             if(valid) {
    //                 count ++;
    //             }
    //         }
    //     }
    //     cout << count;
    /*
    really nice approach to solve such questions . 
    take int to string and then solve the it in string return stoi(string);

    int x = (char) - '0';     makes int out of a char
    char x = (int) + '0';     makes char out of a int 
    */

    
    
    // int largestInteger(int num) {
    //     string s = to_string(num);
    //     priority_queue<int> oddMaxHeap, evenMaxHeap;
    //     for (auto it : s){
    //         int tmp = it - '0';
    //         tmp % 2 == 0 ? evenMaxHeap.push(tmp) : oddMaxHeap.push(tmp);
    //     }
    //     for (auto &it : s){
    //         int tmp = it - '0';
    //         if (tmp % 2 == 0) it = evenMaxHeap.top() + '0', evenMaxHeap.pop();
    //         else it = oddMaxHeap.top() + '0', oddMaxHeap.pop();
    //     }
    //     return stoi(s);
    // }



    // string columnTitle = "CCA";
    // int power = 0;
    // int ans = 0;
    // for (int i = columnTitle.length() - 1 ; i >= 0; i--){
    //         cout << columnTitle[i] <<"  " << ans << endl;
    //         ans += pow(26,power) * int(columnTitle[i]-'A'+1) ;
    //         power++;
    // }
    // cout << ans;

    // vector<int> even; 
    //     vector<int> odd;
    //     int temp = num;
    //     int ans = 0;
    //     while(temp!= 0) {
    //         int val = temp %10;
    //         if(val %2 == 1) {
    //             odd.push_back(val);
    //         } else {
    //             even.push_back(val);
    //         }
    //         temp /= 10;
    //     }
    //     int mul = 1;
    //     make_heap(even.begin(), even.end());
    //     make_heap(odd.begin(), odd.end());
    //     while(even.size() != 0 || odd.size() != 0) {
    //         if(even.front() > odd.front()) {
    //             ans += even.front() * mul; 
    //             pop_heap(even.begin(), even.end());
    //             even.pop_back();
    //             cout << even.size() <<"  "; 
    //             mul = 10;
    //         } else {
    //             ans += odd.front() * mul;
    //             pop_heap(odd.begin(), odd.end());
    //             odd.pop_back();
    //             mul = 10;
    //         }
    //     }
    //     while(!even.empty()) {
    //         ans += even.front() * mul;
    //         pop_heap(even.begin(), even.end());
    //         even.pop_back();
    //     }
    //     while(!odd.empty()) {
    //         ans += odd.front() * mul;
    //         pop_heap(odd.begin(), odd.end());
    //         odd.pop_back();
    //     }
    //     cout <<  ans;


    // cout << strongPasswordCheckerII("aacd1#Aa");


    return 0;
}