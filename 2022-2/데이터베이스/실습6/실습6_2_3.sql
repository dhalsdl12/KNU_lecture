use KOM_6;

create index idx_buy_userID on buy(userID);
create index idx_buy_prodName on buy(prodName);
create index idx_buy_groupName on buy(groupName);

show index from buy;