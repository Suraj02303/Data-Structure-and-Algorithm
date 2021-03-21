#include<bits/stdc++.h>
#include <math.h> 
using namespace std;
int PHk =0;

void RabinKarp(char Text[], char Pattern[]){
	int p=10019, x=5;
	int N = (unsigned)strlen(Text);
	int M = (unsigned)strlen(Pattern);
	for(int i=0;i<N-M+1;i++){
		int k=i, THk=0;
		for(int j=0;j<M;j++){
			THk = THk+(int)Text[k]*pow(5,j); // calculating the polyhash value of each substring from Text string
			k++;
		}
		
		if(THk%p != PHk%p){
			// if polyhash value are not equal then we can say that both the pattern and TextSubstring are not equal
			continue;	
		}	
		
		else{
			int k=i, count = 0;
		//	cout<<"may be equal";
			for(int j=0;j<M;j++){
				if(Text[k]!=Pattern[j]){
					/* here if the polyhash value of pattern and textSubstring are same but the strings are not equal 
					then we get a false alarm 
					By increasing the value of prime no p we can reduce the false alarm to negligible*/
					
					
					//cout<<"THk "<<THk%p<<"not equal"<<" PHk "<<PHk%p<<endl;
					//cout<<"false alaram"<<endl;  //
					break;	
				}
				k++;	
				count++;
			}
			if(count == M){
				cout<<"Pattern found at index "<<i<<endl;
			}
		}
	}
}

int main(){
	char Text[] ="First of all, understand that India is the land of festivals. However, none of the festivals comes close to Diwali. It is certainly one of the biggest festivals in India. It is probably the brightest festival in the world. People of different religions celebrate Diwali. Most noteworthy, the festival signifies the victory of light over darkness. This also means the triumph of good over evil and knowledge over ignorance. It is known as the festival of lights. Consequently, there are bright lights all over the whole country during Diwali. In this essay on Diwali, we will see the religious and spiritual significance of Diwali. The religious significance of this festival has differences. It varies from one region to another in India. There is an association of many deities, cultures, and traditions with Diwali. The reason for these differences is probably local harvest festivals. Hence, there was a fusion of these harvest festivals into one pan-Hindu festival. According to the Ramayana, Diwali is the day of the return of Rama. This day Lord Rama returned to Ayodhya along with his wife Sita. This return was made after Rama defeated demon King Ravana. Furthermore, Rama’s brother Lakshmana and Hanuman also came back to Ayodhya victorious.There is another popular tradition for the reason of Diwali. Here Lord Vishnu as an incarnation of Krishna killed Narakasura. Narakasura was certainly a demon. Above all, this victory brought the release of 16000 captive girls. Furthermore, this victory shows the triumph of good over evil. This is due to Lord Krishna being good and Narakasura being evil. Association of Diwali to Goddess Lakshmi is the belief of many Hindus. Lakshmi is the wife of Lord Vishnu. She also happens to be the Goddess of wealth and prosperity. According to a legend, Diwali is the night of Lakshmi wedding. This night she chose and wed Vishnu. Eastern India Hindus associate Diwali with Goddess Durga or kali. Some Hindus believe Diwali to be the start of a new year.";
	char Pattern[] = "Diwali";
	int M = (unsigned)strlen(Pattern);
	for(int j=0;j<M;j++){
			PHk = PHk+(int)Pattern[j]*pow(5,j);  // polyhash value of pattern
	}
	RabinKarp(Text, Pattern);
//	SearchPattern(Text , Pattern);
	return 0;
} 
