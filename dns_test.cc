#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>

#include "dns_resolver.h"

void onResolve(const muduo::net::InetAddress& addr)
{
  LOG_INFO << addr.toIp();
}

int main()
{

  muduo::net::EventLoop loop;

  zy::dns_resolver resolver(&loop);
  resolver.resolve("www.baidu.com", boost::bind(&onResolve, _1));
  resolver.resolve("www.qq.com", boost::bind(&onResolve, _1), true);
  resolver.resolve("www.google.com", boost::bind(&onResolve, _1), true);
  resolver.resolve("www.google.com", boost::bind(&onResolve, _1), false);
  resolver.resolve("www.ifeng.com", boost::bind(&onResolve, _1), false);
  resolver.resolve("www.zhihu.com", boost::bind(&onResolve, _1), false);

  resolver.resolve("www.baidu.com", boost::bind(&onResolve, _1));
  resolver.resolve("www.qq.com", boost::bind(&onResolve, _1), true);
  resolver.resolve("www.google.com", boost::bind(&onResolve, _1), true);
  resolver.resolve("www.google.com", boost::bind(&onResolve, _1), false);
  resolver.resolve("www.ifeng.com", boost::bind(&onResolve, _1), false);
  resolver.resolve("www.zhihu.com", boost::bind(&onResolve, _1), false);

  resolver.resolve("www.github.com", boost::bind(&onResolve, _1), false);
  resolver.resolve("www.facebook.com", boost::bind(&onResolve, _1), true);
  
  resolver.resolve("www.hao123.com", boost::bind(&onResolve, _1), false);

  loop.loop();

}
