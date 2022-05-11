#include <eosio/eosio.hpp>
#include <iostream>
using namespace std;
using namespace eosio;

// Message table
struct [[table("message"), contract("talk")]] message {
    uint64_t    id       = {}; // Non-0
    uint64_t    reply_to = {}; // Non-0 if this is a reply
    name user     = {};
    string content  = {};

    uint64_t primary_key() const { return id; }
    uint64_t get_reply_to() const { return reply_to; }
};

using message_table = multi_index<
    "message"_n, message, indexed_by<"by.reply.to"_n, const_mem_fun<message, uint64_t, &message::get_reply_to>>>;

// The contract
class talk : contract {
  public:
    // Use contract's constructor
    using contract::contract;

    // Post a message
    [[action]] 
    void post(uint64_t id, uint64_t reply_to, name user, const string& content) {
        message_table table{get_self(), 0};

        // Check user
        require_auth(user);

        // Check reply_to exists
        if (reply_to) table.get(reply_to);

        // Create an ID if user didn't specify one
        check(id < 1'000'000'000ull, "user-specified id is too big");
        if (!id) id = max(table.available_primary_key(), 1'000'000'000ull);

        // Record the message
        table.emplace(get_self(), [&](auto& message) {
            message.id       = id;
            message.reply_to = reply_to;
            message.user     = user;
            message.content  = content;
        });
    }
};
