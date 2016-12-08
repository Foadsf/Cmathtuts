C                  Fortran subprogram (ftnfctn.f):


      FUNCTION FTNFCTN(STR, LOG)

      REAL FTNFCTN
      CHARACTER*(*) STR
      LOGICAL LOG

      COMMON /FLOAT1/FLOAT1
      COMMON /FLOAT2/FLOAT2
      REAL FLOAT1, FLOAT2
      DATA FLOAT2/2.4/          ! FLOAT1 INITIALIZED IN MAIN

C      PRINT CURRENT STATE OF VARIABLES
       PRINT*, '     IN FTNFCTN: FLOAT1 = ', FLOAT1,
      1                          ';FLOAT2 = ', FLOAT2
       PRINT*, '     ARGUMENTS:    STR = "', STR, '"; LOG = ', LOG

C      CHANGE THE VALUES FOR STR(ING) AND LOG(ICAL)
       STR = 'New Fortran String'
       LOG = .FALSE.

       FTNFCTN = 123.4
       PRINT*, '    RETURNING FROM FTNFCTN WITH ', FTNFCTN
       PRINT*
       RETURN
       END
