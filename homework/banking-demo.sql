select 'All customer data.';
select *
from customer
;

select 'All branch data.';
select *
from branch
;

select 'All account data.';
select *
from account
;

select 'All depositor data.';
select *
from depositor
;

select 'All loan data.';
select *
from loan
;

select 'All borrower data.';
select *
from borrower
;

select 'Names and cities of all borrowers';
select distinct customer.customer_name, customer_city
from borrower, customer
where borrower.customer_name = customer.customer_name
;


select 'Set of names and cities of customers who have a loan at Perryridge branch';
select distinct C.customer_name, customer_city
from customer C, borrower B, loan L
where C.customer_name = B.customer_name and 
	B.loan_number = L.loan_number and 
 	  branch_name = 'Perryridge'
;

select 'Numbers of accounts with balances between 700 and 900.';
select account_number
from account
where balance between 700 and 900
;

select 'Names of customers on streets with names ending in "Hill".';
select customer_name
from customer
where customer_street like '%Hill'
;

select 'Names of customers with both accounts and loans at Perryridge branch.';
select distinct customer_name
from borrower, loan
where borrower.loan_number = loan.loan_number and
    branch_name = 'Perryridge' and
	customer_name in (select customer_name
				from account, depositor
				where account.account_number =
					depositor.account_number and
					   branch_name = 'Perryridge')
;

select 'Names of customers with an account but not a loan at Perryridge branch.';
select distinct customer_name
from account, depositor
where account.account_number = depositor.account_number and
	branch_name = 'Perryridge' and
	customer_name not in (select customer_name
				from loan, borrower
				where loan.loan_number = 
					borrower.loan_number and 
					   branch_name = 'Perryridge')
;

select 'Names and cities of all borrowers.';
select distinct C.customer_name, customer_city
from borrower B, customer C
where B.customer_name = C.customer_name
;

select 'Set of names of customers with accounts at a branch where Hayes has';
select 'An account.';
select distinct D.customer_name
from depositor D, account A
where D.account_number = A.account_number and
    branch_name in
	(select branch_name
	from depositor Dh, account Ah
	where Dh.account_number = Ah.account_number and
	    D.customer_name = 'Hayes')
;


select 'Set of names of branches whose assets are greater than the assets of';
select 'some branch in Brooklyn';
select distinct T.branch_name
from branch T, branch S
where T.assets > S.assets and
	S.branch_city = 'Brooklyn'
;

select 'Set of names of branches whose assets are greater than the assets of';
select 'All branches in Brooklyn';
select branch_name
from branch
where assets > all
	(select assets
	from branch
	where branch_city = 'Brooklyn')
;

select 'Names of customers with both accounts and loans at Perryridge branch';
select '(using "exists").';
select customer_name
from customer
where exists (select *
		from account, depositor
		where account.account_number = depositor.account_number and
			depositor.customer_name =
			customer.customer_name and
 			branch_name = 'Perryridge')
	and exists (select *
		from loan, borrower
 		where loan.loan_number = borrower.loan_number and
			borrower.customer_name =
			customer.customer_name and
 			branch_name = 'Perryridge')
;

select 'Names of customers with an account but not a loan at Perryridge branch';
select '(using "exists").';
select customer_name
from customer
where exists (select *
		from account, depositor
		where account.account_number = depositor.account_number and
			depositor.customer_name = customer.customer_name and
			branch_name = 'Perryridge')
	and not exists (select *
		from loan, borrower
 		where loan.loan_number = borrower.loan_number and
			borrower.customer_name = customer.customer_name and
			branch_name = 'Perryridge')
;

select 'Set of names of customers at Perryridge branch, in alphabetical order.';
select distinct customer_name
from borrower, loan, branch
where borrower.loan_number = loan.loan_number and
	loan.branch_name = 'Perryridge'
order by borrower.customer_name
;

select 'Loan data, ordered by decreasing amounts, then increasing loan numbers.';
select *
from loan
order by amount desc, loan_number asc
;

select 'Names of branches having at least one account, with average account balances.';
select branch_name, avg(balance)
from account
group by branch_name
;

select 'Names of branches having at least one account, with size of set of customers';
select 'having at least one account at that branch.';
select branch_name, count(distinct customer_name)
from depositor, account 
where depositor.account_number = account.account_number
group by branch_name
;

select 'The average balance of all accounts.';
select avg(balance)
from account
;

select 'Names of branches having at least one account, with average balances of';
select 'Accounts at each branch, if that average is above 700.';
select branch_name, avg(balance)
from account
group by branch_name
having avg(balance) > 700
;

select 'Name(s) of branch(es) having largest average balance.';
select branch_name
from account
group by branch_name
having avg(balance) >= all(select avg(balance)
				from account
				group by branch_name)
;

select 'The number of customers.';
select count(*)
from customer
;

select 'Average balance of all customers in Harrison having at least 2 accounts.';
select avg(balance)
from depositor, account, customer
where depositor.customer_name = customer.customer_name and
	depositor.account_number = account.account_number and
	customer_city = 'Harrison'
group by depositor.customer_name
having count(distinct account.account_number) >= 2
;
