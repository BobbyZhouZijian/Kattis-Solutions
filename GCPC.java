import java.util.*;

public class GCPC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Solution sln = new Solution(n);
        for (int i = 0; i < m; ++i) {
            int t = sc.nextInt();
            int p = sc.nextInt();
            System.out.println(sln.update(t, p));
        }
    }
}

class Pair implements Comparable<Pair> {
    int score;
    long penalty;
    int team;
    public Pair(int score, long penalty, int team) {
        this.score = score;
        this.penalty = penalty;
        this.team = team;
    }

    @Override
    public int compareTo(Pair o) {
        if (o.score == score) {
            if (penalty == o.penalty) {
                return o.team - team;
            }
            return o.penalty > penalty ? 1 : -1;
        }
        return score - o.score;
    }

    @Override
    public String toString() {
        return String.format("[%d, %d]", team, score);
    }
}

class Solution {

    // TODO: Include your data structures here
    Pair[] teams;
    TreeSet<Pair> better;

    public Solution(int numTeams) {
        // TODO: Construct/Initialise your data structures here
        better = new TreeSet<>();
        teams = new Pair[numTeams + 1];
        for (int i = 0; i < numTeams + 1; ++i) {
            teams[i] = new Pair(0, 0, i);
        }
    }

    public int update(int team, long newPenalty){
        // TODO: Implement your update function here
        Pair cur = teams[team];
        better.remove(cur);
        teams[team] = new Pair(cur.score + 1, cur.penalty + newPenalty, team);

        if (team == 1) {
            while (!better.isEmpty() && teams[1].compareTo(better.first()) > 0) {
                better.pollFirst();
            }
        } else if (teams[team].compareTo(teams[1]) > 0) {
            better.add(teams[team]);
        }
        return better.size() + 1;
    }
}