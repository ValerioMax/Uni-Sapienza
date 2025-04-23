from e_store.customer.generic_customer import GenericCustomer

class PromotionalCustomer(GenericCustomer):
    def send_money(self, money):
        money_sent = money * 1.05
        self.balance -= money_sent
        return money_sent