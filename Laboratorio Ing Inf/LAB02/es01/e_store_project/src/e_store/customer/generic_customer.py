class GenericCustomer:
    def __init__(self, name: str, password: str, balance: float):
        self.name = name
        self.password = password
        self.balance = balance        
    
    def send_money(self, money):
        money_sent = money
        self.balance -= money_sent
        return money_sent
    