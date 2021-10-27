### cmd 

#### 性能检测
valgrind --tool=callgrind ${exe}
gprof2dot -f callgrind callgrind.out.${id} |dot -Tpng -o report-${id}.png

sudo perf record --call-graph dwarf -g  ${exe}
sudo perf report -i 

#### 数据包
tcpdump -i any port ${port} -nn -vv ${name}.pcap
使用Wireshark打开pcap文件


#### clang 调试
apt install lldb

#### docker 
1. push 
for i in $(docker images | grep harbor | awk '{printf("%s:%s\n",$1,$2)}'); do docker push $i; done
2. remove
docker rmi -f $(docker images | grep "vect" | awk '{print $3}') 
3. pull

4. rename
```
#!/bin/bash

images=(
quay.io/prometheus/alertmanager:v0.21.0
)
echo "s"
for imageName in ${images[@]};
do
name=`echo $imageName| awk -F'/' '{print $NF}'`
echo $name
echo $imageName
docker pull $imageName
docker tag ${imageName} harbor.vectbase.com/library/${name} 
done

```

#### git 
1. git submodule foreach git reset --hard
2. git submodule update --init --recursive
