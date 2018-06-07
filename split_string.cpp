#include <time_calc.h>
#include <string>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct data_t
{
	data_t (char* p, int length) 
		: data (p), len (length)
    {}

	char* data;
	int len;
};

#if 0
void split_to_vector (std::string& str, std::vector<data_t>& vec, char sep = ',')
{
	char* p = const_cast<char*>(str.c_str ());
	ssize_t idx[64] = {0};
	int comma_len = 0;
	
	vec.clear ();
	idx[comma_len] = -1;
	size_t str_len = str.length ();
	ssize_t i = 0;
	for (i = 0; i < str_len; i += 4) {
		if (*(p + i) == sep) {
			++comma_len;
			idx[comma_len] = i;
		}

		if (*(p + i + 1) == sep) {
			++comma_len;
			idx[comma_len] = i + 1;
		}

		if (*(p + i + 2) == sep) {
			++comma_len;
			idx[comma_len] = i + 2;
		}

		if (*(p + i + 3) == sep) {
			++comma_len;
			idx[comma_len] = i + 3;
		}
	}

	if (i - 3 < str_len) {
		if (*(p + i - 3) == sep) {
			++comma_len;
			idx[comma_len] = i - 3;
		}
	}

	if (i - 2 < str_len) {
		if (*(p + i - 2) == sep) {
			++comma_len;
			idx[comma_len] = i - 2;
		}
	}

	if (i - 1 < str_len) {
		if (*(p + i - 1) == sep) {
			++comma_len;
			idx[comma_len] = i - 1;
		}
	}


	int ii = 0;
	for (; ii < comma_len; ++ii) {
		/// data_t d;
		
		/// d.data = p + idx[i] + 1;
		/// d.len = idx[i + 1] - idx[i] - 1;
		vec.emplace_back (p + idx[ii] + 1, idx[ii + 1] - idx[ii] - 1);
		vec[ii].data[vec[ii].len] = '\0';
	}
	/// data_t d;
	/// d.data = p + idx[i] + 1;
	/// d.len = str_len - idx[i] - 1;
	/// d.data[d.len] = '\0';
	vec.emplace_back (p + idx[ii] + 1, str_len - idx[ii] - 1);
	vec[ii].data[vec[ii].len] = '\0';
}
#endif

void split_to_vector (char* str, size_t str_len, std::vector<data_t>& vec, char sep = ',')
{
	char* p = str;
	ssize_t idx[64] = {0};
	int comma_len = 0;
	
	vec.clear ();
	idx[comma_len] = -1;
	ssize_t i = 0;
	for (i = 0; i < str_len; i += 4) {
		if (*(p + i) == sep) {
			++comma_len;
			idx[comma_len] = i;
		}

		if (*(p + i + 1) == sep) {
			++comma_len;
			idx[comma_len] = i + 1;
		}

		if (*(p + i + 2) == sep) {
			++comma_len;
			idx[comma_len] = i + 2;
		}

		if (*(p + i + 3) == sep) {
			++comma_len;
			idx[comma_len] = i + 3;
		}
	}

	if (i - 3 < str_len) {
		if (*(p + i - 3) == sep) {
			++comma_len;
			idx[comma_len] = i - 3;
		}
	}

	if (i - 2 < str_len) {
		if (*(p + i - 2) == sep) {
			++comma_len;
			idx[comma_len] = i - 2;
		}
	}

	if (i - 1 < str_len) {
		if (*(p + i - 1) == sep) {
			++comma_len;
			idx[comma_len] = i - 1;
		}
	}


	int ii = 0;
	for (; ii < comma_len; ++ii) {
		/// data_t d;
		
		/// d.data = p + idx[i] + 1;
		/// d.len = idx[i + 1] - idx[i] - 1;
		vec.emplace_back (p + idx[ii] + 1, idx[ii + 1] - idx[ii] - 1);
		vec[ii].data[vec[ii].len] = '\0';
	}
	/// data_t d;
	/// d.data = p + idx[i] + 1;
	/// d.len = str_len - idx[i] - 1;
	/// d.data[d.len] = '\0';
	vec.emplace_back (p + idx[ii] + 1, str_len - idx[ii] - 1);
	vec[ii].data[vec[ii].len] = '\0';

}

#if 0
int 
main ()
{
	std::vector<data_t> vec;

timer_xxx x;
for (int j = 0; j < 10000000; ++j) {
	split_to_vector (str, vec);

	for (size_t i = 0; i < vec.size (); ++i) {
	///	char tmp = *(vec[i].data + vec[i].len);
	///	*(vec[i].data + vec[i].len) = '\0';
		/// printf ("|%s|, len: %d\n", vec[i].data, vec[i].len);	
#if 1
		if (vec[i].data == (char *)0x234343) {
			printf ("%d\n", vec[i].len);
		}
#endif
	///	*(vec[i].data + vec[i].len) = tmp;
	}
}
}
#endif
