def tally(rows):
    teams = {}

    def init_team(team_name):
        if team_name not in teams:
            teams[team_name] = {"MP": 0, "W": 0, "D": 0, "L": 0, "P": 0}

    for row in rows:
        if not row:
            continue
            
        team1, team2, outcome = row.split(";")
        
        init_team(team1)
        init_team(team2)
        
        teams[team1]["MP"] += 1
        teams[team2]["MP"] += 1
        
        if outcome == "win":
            teams[team1]["W"] += 1
            teams[team1]["P"] += 3
            teams[team2]["L"] += 1
        elif outcome == "loss":
            teams[team1]["L"] += 1
            teams[team2]["W"] += 1
            teams[team2]["P"] += 3
        elif outcome == "draw":
            teams[team1]["D"] += 1
            teams[team1]["P"] += 1
            teams[team2]["D"] += 1
            teams[team2]["P"] += 1

    sorted_teams = sorted(teams.items(), key=lambda x: (-x[1]["P"], x[0]))

    header = "Team                           | MP |  W |  D |  L |  P"
    result = [header]

    for team, stats in sorted_teams:
        row_str = (
            f"{team:<30} | "
            f"{stats['MP']:>2} | "
            f"{stats['W']:>2} | "
            f"{stats['D']:>2} | "
            f"{stats['L']:>2} | "
            f"{stats['P']:>2}"
        )
        result.append(row_str)

    return result