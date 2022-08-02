create table asset_type(type_id integer, name varchar(10), description varchar(255), created datetime, user_id integer, PRIMARY KEY(type_id));
create table asset(asset_id integer, srl_nbr int(11), type_id int(11), active tinyint(4), created datetime, user_id integer, price float, PRIMARY KEY(asset_id), FOREIGN KEY(type_id) REFERENCES asset_type(type_id));
create table asset_activity(activity_id integer, asset_id int(11), location_id int(11), created datetime, user_id integer, spot varchar(10), PRIMARY KEY(activity_id), FOREIGN KEY(asset_id) REFERENCES asset(asset_id), FOREIGN KEY(location_id) REFERENCES asset_location(location_id));
create table asset_location(location_id integer, name varchar(10), description varchar(255), created datetime, user_id integer, PRIMARY KEY(location_id));

insert into asset_location values (1, "WHSE", "Warehouse","2014-01-13 11:58:57", 1);
insert into asset_location values (2, "SHLF", "Shelf","2014-01-13 11:59:11", 1);
insert into asset_location values (3, "CUST", "Customer","2014-01-13 12:09:44", 1);

insert into asset_type values (1, "TMT", "Tomato", "2012-01-13 11:58:57", 1);
insert into asset_type values (2, "SBRY", "Strawberry", "2012-01-12 11:58:57", 1);
insert into asset_type values (3, "BBRY", "Blueberry", "2012-01-11 11:58:57", 1);

insert into asset values (1, 123, 1, 1, "2015-01-11 11:58:57", 1, 1.99);
insert into asset values (2, 456, 1, 1, "2015-01-11 11:58:57", 1, 1.99);
insert into asset values (3, 789, 2, 1, "2015-01-11 11:58:57", 1, 1.99);
insert into asset values (4, 889, 3, 1, "2015-01-11 11:58:57", 1, 1.99);

insert into asset_activity values (1, 1, 3, "2016-01-11 11:58:57", 1, "Test");
insert into asset_activity values (2, 1, 2, "2015-01-12 11:58:57", 1, "Test");
insert into asset_activity values (3, 1, 3, "2015-01-14 11:58:57", 1, "Test");
insert into asset_activity values (4, 2, 3, "2015-01-14 11:58:57", 1, "Test");
insert into asset_activity values (5, 4, 3, "2016-01-11 11:58:57", 1, "Test");
-- insert into asset_activity(2, 2, 3, "2015-01-12 11:58:57", 1, "Test");

SELECT date(AA.created) AS "date", COUNT(AA.asset_id) as "number of unreturned asset"
FROM asset_activity AS AA, asset AS A
WHERE AA.asset_id =  A.asset_id AND AA.location_id = 3 AND  A.type_id = 1 AND AA.created = (SELECT max(created) from asset_activity AS AA2 WHERE AA.asset_id = AA2.asset_id)
GROUP BY AA.created;

SELECT DISTINCT  A.srl_nbr as "asset serial numbers"
FROM asset AS A, asset_activity AS AA
WHERE AA.asset_id =  A.asset_id AND AA.location_id = 3 AND "2016-01-11" = date((SELECT max(created) from asset_activity AS AA2 WHERE AA.asset_id = AA2.asset_id));

