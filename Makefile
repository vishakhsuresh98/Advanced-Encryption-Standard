CC = g++ -std=c++11

all: main.o bin_to_hex.o decrypt.o encrypt.o exor.o gallois_field_and.o generate_key.o get_round_constant.o get_round_keys.o hex_to_bin.o hex_to_dec.o inverse_mix_columns.o inverse_s_box_substitution.o inverse_shift_rows.o key_expansion.o mix_columns.o rotate_word.o s_box_substitution.o shift_rows.o
	$(CC) main.o bin_to_hex.o decrypt.o encrypt.o exor.o gallois_field_and.o generate_key.o get_round_constant.o get_round_keys.o hex_to_bin.o hex_to_dec.o inverse_mix_columns.o inverse_s_box_substitution.o inverse_shift_rows.o key_expansion.o mix_columns.o rotate_word.o s_box_substitution.o shift_rows.o
main.o: main.cpp encrypt.h generate_key.h get_round_keys.h
	$(CC) -c main.cpp	
bin_to_hex.o: bin_to_hex.cpp bin_to_hex.h
	$(CC) -c bin_to_hex.cpp
decrypt.o: decrypt.cpp decrypt.h exor.h bin_to_hex.h inverse_s_box_substitution.h inverse_shift_rows.h inverse_mix_columns.h
	$(CC) -c decrypt.cpp	
encrypt.o: encrypt.cpp encrypt.h exor.h bin_to_hex.h s_box_substitution.h shift_rows.h mix_columns.h
	$(CC) -c encrypt.cpp
exor.o: exor.cpp exor.h hex_to_bin.h
	$(CC) -c exor.cpp
gallois_field_and.o: gallois_field_and.cpp gallois_field_and.h exor.h hex_to_bin.h bin_to_hex.h
	$(CC) -c gallois_field_and.cpp
generate_key.o: generate_key.cpp generate_key.h
	$(CC) -c generate_key.cpp
get_round_constant.o: get_round_constant.cpp get_round_constant.h
	$(CC) -c get_round_constant.cpp
get_round_keys.o: get_round_keys.cpp get_round_keys.h key_expansion.h
	$(CC) -c get_round_keys.cpp	
hex_to_bin.o: hex_to_bin.cpp hex_to_bin.h
	$(CC) -c hex_to_bin.cpp
hex_to_dec.o: hex_to_dec.cpp hex_to_dec.h
	$(CC) -c hex_to_dec.cpp
inverse_mix_columns.o: inverse_mix_columns.cpp inverse_mix_columns.h exor.h gallois_field_and.h bin_to_hex.h
	$(CC) -c inverse_mix_columns.cpp
inverse_s_box_substitution.o: inverse_s_box_substitution.cpp inverse_s_box_substitution.h hex_to_dec.h
	$(CC) -c inverse_s_box_substitution.cpp	
inverse_shift_rows.o: inverse_shift_rows.cpp inverse_shift_rows.h rotate_word.h
	$(CC) -c inverse_shift_rows.cpp	
key_expansion.o: key_expansion.cpp key_expansion.h rotate_word.h s_box_substitution.h get_round_constant.h exor.h bin_to_hex.h hex_to_bin.h
	$(CC) -c key_expansion.cpp
mix_columns.o: mix_columns.cpp mix_columns.h exor.h gallois_field_and.h bin_to_hex.h
	$(CC) -c mix_columns.cpp
rotate_word.o: rotate_word.cpp rotate_word.h
	$(CC) -c rotate_word.cpp	
s_box_substitution.o: s_box_substitution.cpp s_box_substitution.h hex_to_dec.h
	$(CC) -c s_box_substitution.cpp
shift_rows.o: shift_rows.cpp shift_rows.h rotate_word.h
	$(CC) -c shift_rows.cpp
clean:
	rm *.o
	rm a.out