namespace hellmath {

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

bool display_post(AccountStatus& poster, AccountStatus& user) {
    if (poster == AccountStatus::troll) {
        if (user == AccountStatus::troll)
            return true;
        else
            return false;
    } else {
        return true;
    }
}

bool permission_check(Action& action, AccountStatus& acc_status) {
    switch (action) {
        case (Action::read):
            return true;
        break;

        case (Action::remove):
            if (acc_status == AccountStatus::mod)
                return true;
            return false;
        break;

        case (Action::write) :
            if (acc_status == AccountStatus::guest)
                return false;
            return true;
        break;

        default:
            return false;
        break;
    }
}

bool valid_player_combination(AccountStatus& acc1, AccountStatus& acc2) {
    if (acc1 == AccountStatus::guest || acc2 == AccountStatus::guest)
        return false;
    if (acc1 == AccountStatus::troll || acc2 == AccountStatus::troll) {
        if (acc1 == AccountStatus::troll and acc2 == AccountStatus::troll)
            return true;
        else
            return false;
    }
    return true;
}

bool has_priority(AccountStatus& acc1, AccountStatus& acc2) {
    int acc1_priority = static_cast<int>(acc1);
    int acc2_priority = static_cast<int>(acc2);

    if (acc1_priority > acc2_priority)
        return true;
    return false;
}

}  // namespace hellmath
