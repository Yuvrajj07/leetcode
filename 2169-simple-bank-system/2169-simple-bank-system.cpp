class Bank {
public:
    vector<long long >bank;
    Bank(vector<long long>& balance) {
        for (int i =0;i<balance.size();i++){
            bank.push_back(balance[i]);
        }
        for (int i=0;i<bank.size();i++) cout<<bank[i]<<" ";
    }
    
    bool transfer(int account1, int account2, long long money) {
         if (account1-1>bank.size()) return false;
          if (account2-1>bank.size()) return false;
          if (account2==account1 && bank[account2-1]<money) return false;
          if (account2==account1) return true; 
        long long  x=bank[account1-1];
        long long  y=bank[account2-1];
        if (x<money) return false;
        bank[account1-1]=x-money;
        bank[account2-1]=y+money;
        return true;
    }
    
    bool deposit(int account, long long money) {
         if (account-1>bank.size()) return false;
        bank[account-1]=bank[account-1]+money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account-1>bank.size()) return false;
        long long  x= bank[account-1];
        if (x<money) return false;
        bank[account-1]=x-money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */