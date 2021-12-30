package szu.csse.softwaretesting.exp3;

public class Date {
	private int year;
	private int month;
	private int day;	
	private int[] days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	public Date() {
		this.year = 1970;
		this.month = 1;
		this.day = 1;
	}
	
	public Date(int y, int m, int d) {
		if (isValid(y,m,d)) {
			this.year = y;
			this.month = m;
			this.day = d;
		}
		else {
			this.year = 1970;
			this.month = 1;
			this.day = 1;
		}
	}

	public boolean isLeap(int y) {
		if (y % 4 == 0) {
			if (y % 100 == 0) {
				if (y % 400 == 0) {
					return true;
				}
				else {
					return false;
				}			
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	
	public boolean isValid(int y, int m, int d) {
		if (y < 1970) return false;
		if (m < 0 || m > 12) return false;
		if (isLeap(y) && m == 2) {
			if (d < 0 || d > days[m]+1) return false;
		}
		else {
			if (d < 0 || d > days[m]) return false;
		}				
		return true;
	}
	
	public Date incDays(int ds) {
		if (ds < 0) return decDays(ds);
		if (ds == 0) return this;
		
		int newy, newm, newd, curDays;		
		newd = this.day + ds;
		newm = this.month;
		newy = this.year;
		while (true) {
			curDays = days[newm];
			if (newm == 2 && isLeap(newy)) {
				curDays = curDays + 1;
			}
			if (newd < curDays) break;
			newd = newd - curDays;
			newm = newm + 1;
			if (newm > 12) {
				newm = 1;
				newy = newy + 1;
			}
		}
		return new Date(newy, newm, newd);
	}

	public Date decDays(int ds) {
		if (ds < 0) return incDays(-ds);
		if (ds == 0) return this;
		
		int newy, newm, newd, preDays;		
		newd = this.day + ds;
		newm = this.month;
		newy = this.year;
		while (true) {
			if (newd > 0) break;			
			preDays = days[newm];
			if (newm == 2 && isLeap(newy)) {
				preDays = preDays + 1;
			}
			newd = newd + preDays;
			newm = newm - 1;
			if (newm <= 0) {
				newm = 12;
				newy = newy - 1;
				if (newy < 1970) return new Date();
			}
		}
		return new Date(newy, newm, newd);
	}

	/*
	public Date nextDate() {
		return incDays(1);
	}
	*/
	
	/*
	public Date preDate() {
		return decDays(1);
	}
	*/
	
	/*
	public String toString() {
		return "The date is " + year + "-" + month + "-" + day;
	}
	*/
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date d = new Date(2020, 11, 23);
		Date d1 = d.incDays(-3650);
		Date d2 = d1.decDays(-3650);
		Date d3 = d2.incDays(1);
		Date d4 = d1.incDays(3650);
		System.out.println(d);
		System.out.println(d1);
		System.out.println(d2);
		System.out.println(d3);
		System.out.println(d4);
	}

}
