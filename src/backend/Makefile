JFLAGS = -g
JC = javac
JVM= java

FILE=
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java
CLASSES = \
	User.java \
	Event.java \
	Transaction.java \
	ProcessUsers.java \
	ProcessEvents.java \
	processTransactions.java \
	UpdateFiles.java \
	Backend.java

MAIN = Backend

TESTS = \
	ProcessEventsTest.java ProcessUsersTest.java processTransactionsTest.java

default: classes

classes: $(CLASSES:.java=.class)

run: classes
	$(JVM) $(MAIN) "../../files/dailyTransactionFile.txt" "../../files/userAccounts.txt" "../../files/availableTickets.txt"

clean:
	$(RM) *.class

test: classes
	$(JVM) org.junit.* $(TESTS)
