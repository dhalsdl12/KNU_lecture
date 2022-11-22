use KOM_6;

create index idx_buy_userID_prodName on buy(userID, prodName);

show index from buy;