string minWindow(string s, string t)
{
	// Write your Code here
	int n =s.size(),m = t.size();
	int ans = n+1,start=-1;
	for(int i=0;i<n;i++){
		if(s[i]!=t[0])
			continue;
		int st = i+1;
		int ct = 1;
		while(ct<m and st<n){
			if(s[st]==t[ct])
			{
				st++;
				ct++;
			}
			else
				st++;
		}
		if(ct==m and ans>(st-i)){
			ans = (st-i);
			start = i;
		}
	}
	return start==-1?"":s.substr(start,ans);
}