class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
          Map<Integer, List<Integer>> map = new TreeMap<>();
        for (int i = 0; i < mat.length; i++) {
            int a = 0;
            int b = mat[0].length;
            while (a < b) {
                int j = a + (b - a) / 2;
                if (mat[i][j] == 1) {
                    a = Math.max(a + 1, j);
                } else {
                    b = j;
                }
            }
            if (map.containsKey(a)) {
                map.get(a).add(i);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(a, list);
            }
        }
        int i = 0;
        int[] rows = new int[k];
        for (List<Integer> list : map.values()) {
            for (int index : list) {
                rows[i] = index;
                if (++i == k) break;
            }
            if (i == k) break;
        }
        return rows;
    }
    
}