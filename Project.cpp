//brokerage class
class Brokerage {
public: 
	//vector of transactions
	vector<Transaction> transaction_vec;
	//vecctor of patrons
	vector<Patron> patron_vec;
	vector<Patron> getPatron_cashAccounts(){
		//iterate through vector and check if it is a cash account and add to new vector
	}
	brokerageState(Stock::type){
		for(int i = 0; i )//iterate through vector of patrons and count up all the shares of that type and output the number
		
	}
	brokerageState(string patron){
		vector<Patron> p = this.getPatron_cashAccounts(); //if cash, output all shares that are held by all the patrons
		//if all, output all shares of each stock type and all the ones held by each patron
	}
	
private:
}

//transition struct
struct Transaction : Patron{
	public:
		Transaction(double shares, Patron::name, string type, Share::share, Stock::stock, Chrono::Date date, Chrono::Time time);
		{		
			if(type == "buy"){
				name.getPortfolio().set(share)+=shares;	
				double p = stock.getPrice()*shares;
				name.removeCash(p);
			}
			else if(type == "sale"){
				name.getPortfolio().set(share)-=shares;	
				double p = stock.getPrice()*shares;
				name.addCash(p);
			}			
		}
		Transaction(double amount, string type, Patron name){
			cout << "please enter 'add' or 'remove'" << endl;
			cin >> type;
			
			switch(type){
				case "add": 
					name.addCash(amount);
					break;
				case "remove":
					name.removeCash(amount);
					break;
				default:
					cout << "wrong input, please enter 'add' or 'remove'" << endl;
			}
		}
		getType(string s){
			return type;
		}
	private:
		string type;
}