struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
  void withdraw_money(int& balance){
      if(balance > amount){
          balance -= amount;
          success = true;
      }
  }
  void deposit_money(int& balance){
      balance += amount;
      success = true;
  }
  void call(int& balance) 
  {
    switch (action)
    {
    case deposit:
      deposit_money(balance);
      break;
    case withdraw:
      withdraw_money(balance);
      break;
    default: break;
    }
  }
  void undo(int& balance) 
  {
    if(!success) return;
    switch (action)
    {
    case withdraw:
      deposit_money(amount);
      break;
    case deposit:
      withdraw_money(amount);
      break;
    default: break;
    }
  }
};


struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    cmd.call(balance);
  }
};
