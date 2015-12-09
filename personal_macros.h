#ifndef PERSONAL_MACROS
#define PERSONAL_MACROS

	#ifdef QT_DEBUG
	   #define D(a) ui->labelDebug->setText(a);
	 #else
	   #define D(a) //do nothing
		//delete ui->labelDebug;
	#endif


#endif // PERSONAL_MACROS

