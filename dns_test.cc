#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>

#include "dns_channel.h"

void onResolve(const muduo::net::InetAddress& addr)
{
  LOG_INFO << addr.toIp();
}

int main()
{

  muduo::net::EventLoop loop;

  zy::dns_channel channel(&loop);
  channel.resolve("www.baidu.com", boost::bind(&onResolve, _1));
  channel.resolve("www.qq.com", boost::bind(&onResolve, _1), true);
  channel.resolve("www.google.com", boost::bind(&onResolve, _1), true);
  channel.resolve("www.google.com", boost::bind(&onResolve, _1), false);
  channel.resolve("www.ifeng.com", boost::bind(&onResolve, _1), false);
  channel.resolve("www.zhihu.com", boost::bind(&onResolve, _1), false);

  channel.resolve("www.baidu.com", boost::bind(&onResolve, _1));
  channel.resolve("www.qq.com", boost::bind(&onResolve, _1), true);
  channel.resolve("www.google.com", boost::bind(&onResolve, _1), true);
  channel.resolve("www.google.com", boost::bind(&onResolve, _1), false);
  channel.resolve("www.ifeng.com", boost::bind(&onResolve, _1), false);
  channel.resolve("www.zhihu.com", boost::bind(&onResolve, _1), false);

  channel.resolve("www.github.com", boost::bind(&onResolve, _1), false);
  channel.resolve("www.facebook.com", boost::bind(&onResolve, _1), true);

  loop.loop();

}