#include <cstdio>
#include <numeric>

#include <kungfu.h>
#include <kungfu/python/init.h>
#include <kungfu/utils/trace.hpp>

DEFINE_TRACE_CONTEXT(kungfu);

std::unique_ptr<kungfu::Peer> _default_peer;

void kungfu_python_init() { _default_peer.reset(new kungfu::Peer); }

void kungfu_python_finialize() { _default_peer.reset(nullptr); }

uint64_t kungfu_uid() { return _default_peer->Uid(); }

int kungfu_detached() { return _default_peer->Detached(); }

int kungfu_rank() { return _default_peer->Rank(); }

int kungfu_size() { return _default_peer->Size(); }

int kungfu_local_rank() { return _default_peer->LocalRank(); }

int kungfu_local_size() { return _default_peer->LocalSize(); }

void kungfu_barrier() { _default_peer->Barrier(); }

int kungfu_propose_new_size(int new_size)
{
    return _default_peer->ProposeNewSize(new_size);
}

int kungfu_check_interference(int idx) {return _default_peer->CheckInterference(idx); }

int kungfu_change_strategy() { return _default_peer->ChangeStrategy(); }

void kungfu_log_stats(int idx) { return _default_peer->LogStats(idx); }

void kungfu_print_strategy_stats() { _default_peer->PrintStategyStats(); }
