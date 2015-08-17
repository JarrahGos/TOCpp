TOCpp
=====

No longer maintained. 
================
This repo is no longer maintained and is unfinished. Feel free to repurpose to your own means. 
All code is untested. 

TOC Repositry for 19 Div

Scope

TOC19 is a program designed for customer centered shopping in a small store environment. It is based on the idea that each customer will be a member of the organisation, and will have an account which can be charged later.

As such, TOC19 allows the managers of the store to allow the store to run itself, simpily collecting the bills at the end of each cycle and then distributing them to the users.

Method

TOC19 uses both a user system and an admin system to achieve it's goal.

User

The user is able to enter their login details, create a cart with the items and quantities of items that they desire, review those items and have them enetered to their account.

Admin

The manager, further refered to as admin is able to administer the program from a select user account. A new menu appears when this account is invoked, allowing admin options such as adding new members or products, retreving billing data, or reseting billing cycles. Every action required by the admin to run the store is encorporated into this menu. The admin is also the only user with the permissions to close the program for maintenance of the system.

Security

The programs security is heavily based on ease of use over security. The main security implementation is that of unknown IDs. Users are unlikely to know the id of another and thus are unlikely to be able to log in. The admin account has it's own ID, completly different to the ids of the other users.

Passwords have not been implemented in this system for normal users. However, they may become useful if security questions are raised in regards to the incorrect use of the user systems. These would have to be hashed and added to the database.

The admin system contains a password, which is stored as an SHA1 hash in the person database. This is changeable within the program.

Export

The program will come with a bash script containing the code needed to export the admin form of both the product and person database to a usb. As this program will be running on a rasberry pi, this script will take advantage of the fact that the hardware will likely only have one USB plugged in at a single time.

Rewrite

This program is a rewrite of TOC19, which was origionally written in java. This change has occured due to two factors. Performance and portability. The latter being due to the fact that the javafx implementation for the raspberry pi uses the framebuffer rather than X11.
The rewrite will be using QT5. Specifically, QT Quick and the QT Creator IDE. 
The old project can be found at the following link: https://github.com/jarrah-95/TOC19
