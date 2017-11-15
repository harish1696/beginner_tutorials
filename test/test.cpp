/**
 * BSD 3-Clause LICENSE
 *
 * Copyright <2017> <HARISH SAMPATHKUMAR>
 *
 * Redistribution and use in source and binary forms, with or without  
 * modification, are permitted provided that the following conditions are 
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the   
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its 
 * contributors may be used to endorse or promote products derived from this 
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  @file    test.cpp
 *  @author  Harish Sampathkumar
 *  @copyright BSD License
 *
 *  @brief Implementing test cases 
 *
 *  @section DESCRIPTION
 *
 *  This program establishes test cases for the talker 
 *  and listener nodes
 *
 */

/**
 * @brief      testing if the service works properly
 *
 * @param[in]     TESTSuite
 * @param[in]     testchangeStringService
 *
 * @return     none
 */
TEST(TESTSuite, testchangeStringService) {
 // Creating NodeHandle
 ros::NodeHandle n;

 // Create a client object for change_string service
 ros::ServiceClient client = n.serviceClient<beginner_tutorials::change_string>("change_string");

 // creating an object of change_string
 beginner_tutorials::change_string srv;
 
 // assigning input to srv data
 srv.request.in = "Hello";
 
 // checking the existence of the service used 
 bool exists(client.waitForExistence(ros::Duration(10)));
 
 EXPECT_TRUE(exists);

 // checks if the service call works properly
 bool success = client.call(srv);

 EXPECT_TRUE(success);
 
 // compares the input and output string of the service
 EXPECT_STREQ("Hello", srv.response.out.c_str());
}
