#include "talk.hpp"

void talk::post(
    uint64_t id, 
    uint64_t reply_to,
    eosio::name user, 
    const std::string& content
) {
    message_table table{get_self(), 0};

    // Check user
    require_auth(user);

    // Check reply_to exists
    if (reply_to)
        table.get(reply_to);

    // Create an ID if user didn't specify one
    eosio::check(id < 1'000'000'000ull, "user-specified id is too big");
    if (!id)
        id = std::max(table.available_primary_key(), 1'000'000'000ull);

    // Record the message
    table.emplace(get_self(), [&](auto& message) {
        message.id       = id;
        message.reply_to = reply_to;
        message.user     = user;
        message.content  = content;
    });
}