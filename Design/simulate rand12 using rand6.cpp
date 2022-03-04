outcome = (rand6() - 1) * 4 + rand6()

if (outcome > 24) continue;
else return (outcome % 12) - 1;