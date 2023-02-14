pipeline {
    environment {
        imagename = "ewelina9606/aplikacja-kryptograficzna:$BRANCH_NAME-$BUILD_NUMBER-SNAPSHOT"
        DOCKERHUB_CREDENTIALS=credentials('docker-hub-acess-user')
    }
    parameters { 
	string(name: 'VERSION', defaultValue: 'latest', description: '') 
    }
    agent any 
    stages {
        stage('Build') { 
            steps {
                script{   
		  dir('Aplikacja') {
		      	sh "env"
		    	sh "cmake ./"
		    	sh "make"
                  }               
                }
            }
        }
        stage('Test') { 
            steps {
		dir('Aplikacja') {
		    	sh "ctest -T test --no-compress-output"
                }  
            }
        }
        stage('Deploy') { 
            steps {
                script {
                    if (env.TAG_NAME == env.BRANCH_NAME) 
                    {
                        imagename = "ewelina9606/aplikacja-kryptograficzna:$BRANCH_NAME-$BUILD_NUMBER-RELEASE"  
                    }
                }
		dir('Aplikacja') {      
		    sh "docker build -t $imagename ."
                } 		
                sh 'echo $DOCKERHUB_CREDENTIALS_PSW | docker login -u $DOCKERHUB_CREDENTIALS_USR --password-stdin'
            	sh "docker push $imagename"
		//sh "docker rmi $imagename"
            }
        }
    }
    post {
      always {
        // Archive the CTest xml output
        archiveArtifacts (
          artifacts: 'Aplikacja/Testing/**/*.xml',
          fingerprint: true
        )

        // Process the CTest xml output with the xUnit plugin
        xunit (
          testTimeMargin: '3000',
          thresholdMode: 1,
          thresholds: [
            skipped(failureThreshold: '0'),
            failed(failureThreshold: '0')
          ],
        tools: [CTest(
            pattern: 'Aplikacja/Testing/**/*.xml',
            deleteOutputFiles: true,
            failIfNotNew: false,
            skipNoTestFiles: true,
            stopProcessingIfError: true
          )]
        )

      // Clear the source and build dirs before next run
      deleteDir()
    }
  }
}