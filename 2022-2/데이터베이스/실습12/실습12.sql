use classicmodels;

# 2번
select orderNumber, sum(priceEach * quantityOrdered) as '주문량 합계'
		from orderdetails group by orderNumber having sum(priceEach * quantityOrdered) >= 60000;


# 3번
select customerName, count(*) as '주문수' from customers inner join orders 
		where customers.customerNumber = orders.customerNumber
		group by customerName order by count(*) DESC;


# 4번
select lastname, firstname from employees 
		where officeCode in (select officeCode from offices where country = 'USA');


# 5번
create index jobtitle_idx ON employees (jobtitle);
select employeeNumber, lastname, firstname from employees
		where jobtitle = 'Sales Rep';
  
  
# 6번
select customerName, checknumber, paymentdate, amount
		from customers inner join payments using (customerNumber);

drop view if exists customerPayments;
create view customerPayments(customerName, checkNumber, paymentDate, amount)
		as select customerName, checknumber, paymentdate, amount
		from customers inner join payments using (customerNumber);
select * from customerPayments;


# 7번
select customerName, city, state, postalCode, country
		from customers order by customerName;
        
drop procedure if exists GetCustomer;
delimiter $$
	create procedure GetCustomer()
    begin
		select customerName, city, state, postalCode, country
				from customers order by customerName;
	end $$
delimiter ;
call GetCustomer;


# 8번
alter table customers add grade char(20);

drop procedure if exists cursorProc;
set sql_safe_updates=0;
delimiter $$
	create procedure cursorProc()
    begin
		declare eamount float;
		declare count int default 0;
        declare endOfRow boolean default false;
        
        declare cur cursor for 
				select sum(amount) from customers inner join payments using (customerNumber) group by customerNumber;
		declare continue handler for not found set endOfRow = True;
        open cur;
        cursor_loop: loop
			fetch cur into eamount;
            if endOfRow then
				leave cursor_loop;
			end if;
            if eamount >= 300000 then
				update customers set grade = 'best customer' 
						where customerNumber in (select customerNumber 
								from payments group by customerNumber having sum(amount) >= 300000);
			elseif eamount >= 100000 then
				update customers set grade = 'good customer' 
						where customerNumber in (select customerNumber 
								from payments group by customerNumber having sum(amount) >= 100000 and sum(amount) < 300000);
            elseif eamount >= 5000 then
				update customers set grade = 'average customer' 
						where customerNumber in (select customerNumber 
								from payments group by customerNumber having sum(amount) >= 5000 and sum(amount) < 100000);
            end if;
            
		end loop cursor_loop;
		close cur;
    end $$
delimiter ;

call cursorProc();
select customerNumber, customerName, country, grade from customers;

select * from orders order by customerNumber asc;