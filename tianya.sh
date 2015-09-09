#!/bin/bash

if [ $# != 3 ];then
	echo ./tianya.sh save_filename url end_index.
	echo ./tianya.sh 帝国最后的荣耀大明1592抗日援朝 http://bbs.tianya.cn/post-no05-184314 119
	exit;
fi

end_index=$3
url=$2
saved_tmp_filename=$1;
saved_filename=${1}.txt;

#echo $saved_filename : $url : $end_index

for i in `seq 1 $end_index`
do
	lynx -dump $url-$i.shtml | ./filter.pl >> $saved_tmp_filename
done

./merge_line.pl $saved_tmp_filename > $saved_filename
#cp $saved_tmp_filename .a.txt
rm -f $saved_tmp_filename
#============================ filter.pl  ===============================
#!/usr/bin/perl -w

#while (<>) {
#	next if (/^\s*$/);
#	next if (/举报/);
#	next if (/作者/);
#	next if (/mark/);
#	exit if (/^References/);
#
#	printf;
#}
