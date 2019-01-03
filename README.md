# LottoTicketGame

Course: Object Oriented Programming with Design Pattern Language: C++ Semester: Fall 2018

Description of the Game:

This is a 5-player game. The user inputs a minimum(min) value, maximum(max) value,
number of rounds(r) to be played. This information is used to generate a LottoTicket. A
LottoTicket has 15 slots, which has to be randomly filled between the min and max
value(inclusive). Once all tickets are generated, the game starts and will play ‘r’ rounds.
For each round, a random number between min and max(inclusive) is generated and this
value is searched in each ticket to see if it is found in any one of the 15 slots. Please note,
that if a number is repeated in a ticket, then only one occurrence of the number is
considered as found.
The winner is decided by the first player who has all 15 slots revealed/found before the ‘r’
rounds are completed, else the game is considered a draw.

