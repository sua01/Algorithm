import java.io.*;
import java.util.*;

public class Main {
    static int N, T;
    static int[][] F;  // 음식
    static int[][] B;   // 신앙심

    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};

    // 비트마스크 이용
    static final int MINT = 1;
    static final int CHOCO = 2;
    static final int MILK = 4;
    static int[] order = {MINT, CHOCO, MILK, CHOCO|MILK, MINT|MILK, MINT|CHOCO, MINT|CHOCO|MILK};   // 전파 순서

    static class Point{
        int x, y;
        int f;
        public Point(int x, int y, int f){
            this.x = x;
            this.y = y;
            this.f = f;
        }
    }

    static ArrayList<Point>[] leaders = new ArrayList[8];    // 대표자들 저장

    // 1.아침시간 : 신앙심 +1 
    public static void morning(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                B[i][j]++;  // 신앙심 + 1 증가
            }
        }
    }

    // 2. 점심시간
    public static void lunch(){
        for (int i = 1; i < 8; i++) {
            if(leaders[i] == null){
                leaders[i] = new ArrayList<>();
            }
            else{
                leaders[i].clear(); // 대표자 초기화
            }
        }
        boolean[][] visited = new boolean[N+1][N+1];

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N;j++){
                if(!visited[i][j]){
                    // 방문하지 않은 경우
                    int food = F[i][j];
                    ArrayList<Point> group = new ArrayList<>();
                    ArrayDeque<Point> q = new ArrayDeque<>();
                    q.add(new Point(i, j, food));
                    visited[i][j] = true;

                    // 같은 음식일 경우 > 그룹 > 좌표 저장하기
                    while(!q.isEmpty()){
                        Point current = q.poll();
                        group.add(current);

                        for(int d=0; d<4; d++){
                            int nx = current.x + dx[d];
                            int ny = current.y + dy[d];

                            if(nx >= 1 && ny>=1 && nx<=N && ny<=N && !visited[nx][ny] && food == F[nx][ny]){
                                visited[nx][ny] = true;
                                q.add(new Point(nx, ny, food));
                            }
                        }
                    }

                    // 대표자 정하기
                    int maxB = -1;  // 신앙심 최댓값
                    Point leader = null;    // 대표자
                    for(Point p: group){
                        int b = B[p.x][p.y];    // 신앙심
                        if(leader == null ||maxB < b || b == maxB && leader.x > p.x || b == maxB && leader.x == p.x && leader.y > p.y){
                            leader = p;
                            maxB = b;
                        }
                    }

                    // 대표자한테 신앙심 주기
                    B[leader.x][leader.y] += group.size() - 1;
                    leaders[leader.f].add(leader);
                    for(Point p: group){
                        if(p == leader){
                            continue;
                        }
                        B[p.x][p.y]--;
                    }
                }
            }
        }
    }

    // 3. 저녁시간
    
    public static void dinner(){
        boolean[][] visited = new boolean[N+1][N+1];
        // 전파하기
        // 전파 순서
        for(int food : order){
            for(Point leader : leaders[food]){
                if(visited[leader.x][leader.y]) continue; // 전파당했으면 전파X

                int b = B[leader.x][leader.y];  // 전파자 신앙심
                int x = b - 1;  // 간절함
                B[leader.x][leader.y] = 1;  // 전파자의 신앙심은 1됨
                // 전파방향 설정
                int direction = b % 4; 
                int nx = leader.x;
                int ny = leader.y;

                while(x>0){
                    nx += dx[direction];
                    ny += dy[direction];

                    if(nx <1 || ny < 1|| nx > N|| ny>N|| x == 0){
                        // 전파 종료
                        break;
                    }
                    

                    if(food == F[nx][ny]){
                        // 같은 음식이면 전파 X
                        continue;
                    }

                    else{
                        // 다른 음식일 경우 전파
                        if(x > B[nx][ny]){
                            // 전파 성공
                            x -= (B[nx][ny]+1);
                            B[nx][ny]++;
                            F[nx][ny] = food;    
                            visited[nx][ny] = true;
                        }
                        else{
                            // 약한 전파인 경우
                            B[nx][ny] += x;
                            // 전파한 음식 합치기
                            F[nx][ny] |= food;   // 비트마스크 이용
                            visited[nx][ny] = true;
                            x=0;
                            break;
                        }
                        
                    }
                }
            }
            
        }
    }


    // 출력하기
    static void printResult(){
        // 민트초코우유, 민트초코, 민트우유, 초코우유, 우유, 초코, 민트 순
        int[] sum = new int[8];
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                sum[F[i][j]] += B[i][j];
            }
        }

        System.out.println(sum[7]+" "+ sum[3]+" "+sum[5]+ " " + sum[6] +" "+ sum[4] + " "+ sum[2] + " " + sum[1]);

    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 격자 크기, 진행 일수 입력받기
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        // 초기 음식 입력받기
        F = new int[N+1][N+1];
        for(int i=1; i<=N; i++){
            String line = br.readLine();
            for(int j=1; j<=N; j++){
                char food = line.charAt(j-1);
                if(food == 'T'){
                    F[i][j] = MINT;
                }
                else if(food == 'C'){
                    F[i][j] = CHOCO;
                }
                else if(food == 'M'){
                    F[i][j] = MILK;
                }
            }
        }

        // 초기 신앙심 입력받기
        B = new int[N+1][N+1];
        for(int i=1; i<=N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; j++){
                B[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 진행하기
        while(T>0){
            T--;
            // 1.아침시간
            morning();  // 신앙심 + 1

            // 2. 점심시간
            lunch();

            // 3. 저녁시간
            dinner();

            // 결과 출력하기
            printResult();
        }
    }
}