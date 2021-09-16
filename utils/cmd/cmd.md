### cmd 

#### 性能检测
valgrind --tool=callgrind ${exe}
gprof2dot -f callgrind callgrind.out.${id} |dot -Tpng -o report-${id}.png

sudo perf record --call-graph dwarf -g  ${exe}
sudo perf report -i 

#### 数据包
tcpdump -i any port ${port} -nn -vv ${name}.pcap
使用Wireshark打开pcap文件
