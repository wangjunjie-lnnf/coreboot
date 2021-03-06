# SPDX-License-Identifier: BSD-3-Clause

amdfwtoolobj = amdfwtool.o

AMDFWTOOLCFLAGS=-O2 -Wall -Wextra -Wshadow

$(objutil)/amdfwtool/%.o: $(top)/util/amdfwtool/%.c # $(HEADER)
	$(HOSTCC) $(AMDFWTOOLCFLAGS) $(HOSTCFLAGS) -c -o $@ $<

$(objutil)/amdfwtool/amdfwtool: $(addprefix $(objutil)/amdfwtool/,$(amdfwtoolobj))
	printf "   AMDFWTOOL\n"
	$(HOSTCC) $(addprefix $(objutil)/amdfwtool/,$(amdfwtoolobj)) -o $@
