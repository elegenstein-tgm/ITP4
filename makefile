BIN =  ritpp itpp_svc
GEN = itpp_clnt.c itpp_svc.c itpp_xdr.c itpp.h
RPCCOM = rpcgen

all: $(BIN)

ritpp: ritpp.o itpp_clnt.o itpp_xdr.o
	$(CC) -std=c99 -o $@ ritpp.o itpp_clnt.o itpp_xdr.o 

ritpp.o: ritpp.c itpp.h
	$(CC) -std=c99 -g ritpp.c -c

itpp_svc: itpp_proc.o itpp_svc.o itpp_xdr.o
	$(CC) -o $@ itpp_proc.o itpp_svc.o itpp_xdr.o

itpp_proc.o: itpp_proc.c itpp.h

$(GEN): itpp.x
	$(RPCCOM) itpp.x

clean cleanup:
	rm -f $(GEN) *.o $(BIN)

